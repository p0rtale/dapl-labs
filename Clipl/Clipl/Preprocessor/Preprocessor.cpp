#include <Clipl/Preprocessor/Preprocessor.hpp>

#include <Clipl/Logger/Logger.hpp>

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>


namespace preprocessor {

std::string Preprocessor::run(const std::string& cliplFilename, bool debug) {
    CLIPL_INFO("Run Clipl preprocessor (filename={}, debug={})", cliplFilename, debug);

    initRun(cliplFilename, debug);
    CLIPL_INFO("Initialization completed");

    Token tokenPrevious;
    Token tokenCurrent;
    while (!m_StreamStack.empty()) {
        tokenCurrent = scanTokenWithComments();
        if (tokenCurrent.isEnd()) {
            CLIPL_INFO("End of stream");
            m_StreamStack.popStream();
            continue;
        }

        std::string preprocessed;
        switch (tokenCurrent.getType()) {
        case TokenType::NewLine:
            CLIPL_TRACE("Process NewLine");
            preprocessed = "\n";
            break;
        case TokenType::Include:
            CLIPL_TRACE("Process Include");
            preprocessed = processInclude();
            break;
        case TokenType::Define:
            CLIPL_TRACE("Process Define");
            preprocessed = processDefine();
            break;
        case TokenType::IfDef:
            CLIPL_TRACE("Process IfDef");
            preprocessed = processConditionalDefine(false);
            break;
        case TokenType::IfnDef:
            CLIPL_TRACE("Process IfnDef");
            preprocessed = processConditionalDefine(true);
            break;
        case TokenType::EndIf:
            CLIPL_TRACE("Process EndIf");
            preprocessed = processConditionalEnd();
            break;
        case TokenType::Identifier:
            CLIPL_TRACE("Process Identifier");
            preprocessed = processIdentifier(tokenCurrent.getValue());
            break;
        case TokenType::Space:
            CLIPL_TRACE("Process Space");
            if (tokenPrevious.isAmongTypes({
                        TokenType::NewLine,
                        TokenType::Include, TokenType::Define,
                        TokenType::IfDef, TokenType::IfnDef, TokenType::EndIf
                    })) {
                auto spaceCoords = tokenCurrent.getCoords();
                preprocessed = std::string(spaceCoords.End.Column - 1, ' ');
            } else {
                preprocessed = " ";
            }
            break;
        default:
            CLIPL_TRACE("Process Token");
            preprocessed = tokenCurrent.getValue();
        }

        m_PreprocessedString.append(preprocessed);
        tokenPrevious = tokenCurrent;
    }

    CLIPL_INFO("Preprocessor is completed");

    return m_PreprocessedString;
}

void Preprocessor::initRun(const std::string& cliplFilename, bool debug) {
    if (debug) {
        m_Lexer.set_debug(true);
    }
    CLIPL_INFO("Add new stream");
    m_StreamStack.pushStream(std::make_unique<std::ifstream>(cliplFilename));
    m_PreprocessedString.clear();
}

std::string Preprocessor::processDefine() {
    auto token = scanTokenWithComments();
    if (!token.isSpace()) {
        CLIPL_ERROR("processDefine: no Space after keyword");
        return std::string{'\n'};
    }

    auto defineIdentifier = processDefineIdentifier();
    auto parameters = processDefineParameters();
    if (parameters.empty()) {
        m_Defines[defineIdentifier] = "";
    } else {
        m_Defines[defineIdentifier] = concatDefineParameters(parameters);
    }
    return std::string{'\n'};
}

std::string Preprocessor::processDefineIdentifier() {
    auto token = scanTokenWithComments();
    if (token.isIdentifier()) {
        return token.getValue();
    }
    CLIPL_ERROR("processDefineIdentifier: Token ({}) is not Identifier", token.getValue());
    return std::string{};
}

std::vector<std::string> Preprocessor::processDefineParameters() {
    std::vector<std::string> parameters;

    Token token;
    std::string parameter;
    while (!token.isNewLine() && !token.isEnd()) {
        token = scanTokenWithComments();
        if (token.isSpace()) {
            if (!parameter.empty()) {
                parameters.push_back(parameter);
            }
            parameter.clear();
        } else {
            parameter.append(token.getValue());
        }
    }

    if (!parameter.empty()) {
        parameters.push_back(parameter);
    }

    return parameters;
}

std::string Preprocessor::concatDefineParameters(const std::vector<std::string>& parameters) {
    // auto parametersStr = std::accumulate(parameters.begin(), parameters.end(), std::string{},
    //     [](std::string a, std::string b){ return std::move(a) + b + ' '; });
    std::string parametersStr;
    for (const auto& parameter: parameters) {
        parametersStr.append(parameter);
        parametersStr.push_back(' ');
    }
    parametersStr.pop_back();
    return parametersStr;
}

std::string Preprocessor::processConditionalDefine(bool negative) {
    auto token = scanTokenWithComments();
    if (!token.isSpace()) {
        CLIPL_ERROR("processConditionalDefine: no Space after keyword");
        return std::string{'\n'};
    }

    auto defineIdentifier = processDefineIdentifier();
    skipSpacesToLineEnd();

    bool isDefined = m_Defines.contains(defineIdentifier);
    if (isDefined == !negative) {
        CLIPL_TRACE("processConditionalDefine: go inside conditional define");
        m_IsInsideCondDef = true;
    } else {
        CLIPL_TRACE("processConditionalDefine: skip conditional define to EndIf");
        size_t linesCount = 2;  // IfDef + EndIf
        auto firstToken = scanFirstNonSpace();
        while (!firstToken.isEndIf() && !firstToken.isEnd()) {
            ++linesCount;
            if (!firstToken.isNewLine()) {
                skipLine();
            }
            firstToken = scanFirstNonSpace();
        }
        if (firstToken.isEnd()) {
            CLIPL_ERROR("processConditionalDefine: got EOF, EndIf expected");
        }
        skipSpacesToLineEnd();

        return std::string(linesCount, '\n');
    }

    return std::string{'\n'};
}

std::string Preprocessor::processConditionalEnd() {
    if (m_IsInsideCondDef) {
        m_IsInsideCondDef = false;
    } else {
        CLIPL_ERROR("processConditionalEnd: unexpected EndIF");
    }
    return std::string{'\n'};
}

std::string Preprocessor::processInclude() {
    auto token = scanTokenWithComments();
    if (!token.isSpace()) {
        CLIPL_ERROR("processInclude: no Space after keyword");
        return std::string{'\n'};
    }

    auto leftBoundToken = scanTokenWithComments();   
    if (!leftBoundToken.isQuotes() && !leftBoundToken.isAngleBracketLeft()) {
        CLIPL_ERROR("processInclude: no leftBoundToken after space");
        return std::string{'\n'};
    }

    auto rightBoundExpectedType = TokenType::Quotes;
    if (leftBoundToken.isAngleBracketLeft()) {
        rightBoundExpectedType = TokenType::AngleBracketRight;
    }

    std::string includeFilename;
    auto filenameToken = scanTokenWithComments();
    while (filenameToken.getType() != rightBoundExpectedType) {
        std::string value; 
        if (filenameToken.isSpace()) {
            auto spaceCoords = filenameToken.getCoords();
            value = std::string(' ', spaceCoords.End.Column - spaceCoords.Begin.Column);
        } else {
            value = filenameToken.getValue();
        }
        includeFilename.append(value);

        filenameToken = scanTokenWithComments();
    }

    skipSpacesToLineEnd();

    CLIPL_INFO("processInclude: includeFilename=\"{}\"", includeFilename);
    CLIPL_INFO("Add new stream");
    m_StreamStack.pushStream(std::make_unique<std::ifstream>(includeFilename));

    return std::string{'\n'};
}

std::string Preprocessor::processIdentifier(const std::string& identifierValue) {
    if (m_Defines.contains(identifierValue)) {
        return m_Defines[identifierValue];
    }
    return identifierValue;
}

Token Preprocessor::scanTokenWithComments() {
    auto token = m_Lexer.scanToken();
    while (token.isComment()) {
        auto coords = token.getCoords();
        size_t newlinesCount = coords.End.Line - coords.Begin.Line;
        if (newlinesCount > 0) {
            m_PreprocessedString.append(std::string(newlinesCount, '\n'));
        }
        token = m_Lexer.scanToken();
    }

    auto [positionBegin, positionEnd] = token.getCoords();
    CLIPL_TRACE("Scan Token {}({}) {},{}-{},{}",
        static_cast<uint32_t>(token.getType()), token.getValue(),
        positionBegin.Line, positionBegin.Column, positionEnd.Line, positionEnd.Column);

    return token;
}

Token Preprocessor::scanFirstNonSpace() {
    auto token = m_Lexer.scanToken();
    while (token.isSpace()) {
        token = m_Lexer.scanToken();
    }

    auto [positionBegin, positionEnd] = token.getCoords();
    CLIPL_TRACE("Scan Token {}({}) {},{}-{},{}",
        static_cast<uint32_t>(token.getType()), token.getValue(),
        positionBegin.Line, positionBegin.Column, positionEnd.Line, positionEnd.Column);

    return token; 
}

void Preprocessor::skipSpacesToLineEnd() {
    auto token = m_Lexer.scanToken();
    while (token.isSpace()) {
        token = m_Lexer.scanToken();
    }

    auto [positionBegin, positionEnd] = token.getCoords();
    auto tokenType = token.getType();
    if (!token.isNewLine() && !token.isEnd()) {
        CLIPL_ERROR("scanSpacesToLineEnd: unexpected Token {}({}) {},{}-{},{}",
            static_cast<uint32_t>(tokenType), token.getValue(),
            positionBegin.Line, positionBegin.Column, positionEnd.Line, positionEnd.Column);
    }

    CLIPL_TRACE("Scan Token {}({}) {},{}-{},{}",
        static_cast<uint32_t>(tokenType), token.getValue(),
        positionBegin.Line, positionBegin.Column, positionEnd.Line, positionEnd.Column);
}

void Preprocessor::skipLine() {
    auto token = m_Lexer.scanToken();
    while (!token.isNewLine() && !token.isEnd()) {
        token = m_Lexer.scanToken();
    }
}

}  // namespace preprocessor
