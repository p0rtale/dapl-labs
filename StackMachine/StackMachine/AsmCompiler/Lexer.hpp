#pragma once

#include <StackMachine/AsmCompiler/Token.hpp>

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

namespace asm_compiler {

class Lexer {
public:
    Lexer(std::ifstream& input): m_input(input) {}

    bool scan();

    Token nextToken();

private:
    std::istream& nextSymbol(char& symbol);

    bool isIntNumber(std::string numberStr);
    bool isFloatNumber(std::string numberStr);

    char skipLine();

private:
    size_t m_scanPosition = 0;
    std::vector<Token> m_tokens;
    size_t m_currentTokenIndex = 0;

    std::ifstream& m_input;
};

}  // namespace asm_compiler
