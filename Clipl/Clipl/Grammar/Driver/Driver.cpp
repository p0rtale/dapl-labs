#include <Clipl/Grammar/Driver/Driver.hpp>
#include <Clipl/Grammar/Parser/Parser.hpp>
#include <Clipl/Grammar/Lexer/Lexer.hpp>

#include <Clipl/Visitor/DotVisitor.hpp>


namespace clipl {

Driver::Driver(bool traceParsing, bool traceScanning):
    m_Lexer(std::make_unique<Lexer>(*this)),
    m_Parser(*m_Lexer, *this),
    m_TraceParsing(traceParsing),
    m_TraceScanning(traceScanning) {}

// NB: forward decl with Lexer unique ptr
Driver::~Driver() {}

Driver::Result Driver::Parse(const std::string& filename) {
    auto result = Result::kOK;

    m_Filename = filename;
    m_Location.initialize(&m_Filename);
    m_Lexer->set_debug(m_TraceScanning);

    std::ifstream file(m_Filename);
    if (!file.good()) {
        // TODO: handle error
    }
    m_Lexer->yyrestart(&file);

    m_Parser.set_debug_level(m_TraceParsing);
    int parseResult = m_Parser();
    if (parseResult) {
        result = Result::kParseError;
    }

    return result;
}

void Driver::ConvertTreeToDot(const std::string& filename) {
    ast::DotVisitor visitor{filename};
    if (m_Program) {
        visitor.Visit(*m_Program);
    }
}

}  // namespace clipl
