#pragma once

#include <map>
#include <memory>
#include <string>
#include <fstream>

#include <Clipl/Grammar/Parser/Parser.hpp>


namespace clipl {

class Lexer;

class Driver {
public:
    enum class Result {
        kOK = 0,
        kParseError,
    };

public:
    Driver(bool traceParsing = false, bool traceScanning = false);
    ~Driver();

    Result parse(const std::string& filename);

    yy::location& getLocation() {
        return m_Location;
    }

private:
    friend class Lexer;
    std::unique_ptr<Lexer> m_Lexer;
    yy::parser m_Parser;

    std::string m_Filename;

    yy::location m_Location;

    bool m_TraceParsing = false;
    bool m_TraceScanning = false;
};

}  // namespace clipl
