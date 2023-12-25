#pragma once

#include <Clipl/Preprocessor/Lexer/Lexer.hpp>
#include <Clipl/Preprocessor/Streams/Streams.hpp>

namespace preprocessor {

class Preprocessor {
public:
    Preprocessor() = default;

    std::string run(const std::string& cliplFilename, bool debug = false);

private:
    void initRun(const std::string& cliplFilename, bool debug);

    std::string processDefine();
    std::string processDefineIdentifier();
    std::vector<std::string> processDefineParameters();
    std::string concatDefineParameters(const std::vector<std::string>& parameters);

    std::string processConditionalDefine(bool negative = false);
    std::string processConditionalEnd();

    std::string processInclude();

    std::string processIdentifier(const std::string& identifierValue);

    Token scanTokenWithComments();
    Token scanFirstNonSpace();

    void skipSpacesToLineEnd();
    void skipLine();

private:
    Lexer m_Lexer;

    StreamStack m_StreamStack = StreamStack(
        [this](StreamStack::TStreamScope& streamScope) {
            m_Lexer.yyrestart(streamScope.get());
        },
        [this](StreamStack::TStreamScope& streamScope) {
            m_Lexer.yyrestart(streamScope.get());
        }
    );

    std::string m_PreprocessedString;
    std::unordered_map<std::string, std::string> m_Defines;

    bool m_IsInsideCondDef = false;
};

}  // namespace preprocessor
