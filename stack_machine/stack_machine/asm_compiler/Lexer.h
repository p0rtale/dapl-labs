#pragma once

#include <stack_machine/asm_compiler/Token.h>

#include <string>
#include <vector>

namespace asm_compiler {

class Lexer {
public:
    Lexer(std::ifstream& input): m_input(input) {}

    bool scan() {
        char symbol;
        while (nextSymbol(symbol)) {
            if (std::isspace(symbol)) {
                continue;
            }

            if (symbol == ';') {
                symbol = skipLine();
                continue;
            }

            switch (symbol) {
            case '@':
                m_tokens.push_back(Token{TokenType::kAsperand, "@"});
                break;
            case ':':
                m_tokens.push_back(Token{TokenType::kColon, ":"});
                break;
            case '=':
                m_tokens.push_back(Token{TokenType::kEqual, "="});
                break;
            default:
                if (symbol == '+' || symbol == '-' || std::isdigit(symbol)) {
                    std::string numberStr{symbol};
                    while (nextSymbol(symbol) && !std::isspace(symbol)) {
                        numberStr.push_back(symbol);
                    }
                    if (!isNumber(numberStr)) {
                        size_t errPosition = m_scanPosition - numberStr.length() - 1;
                        std::cerr << "Error: invalid number at position " << errPosition << std::endl;
                        return false;
                    }
                    m_tokens.push_back(Token{TokenType::kNumber, numberStr});
                } else if (std::isalpha(symbol) || symbol == '_') {
                    std::string nameStr{symbol};
                    while (nextSymbol(symbol) && !std::isspace(symbol)) {
                        if (!(std::isalpha(symbol) || symbol == '_' || std::isdigit(symbol))) {
                            std::cerr << "Error: invalid name at position " << m_scanPosition << std::endl;
                            return false;
                        }
                        nameStr.push_back(symbol);
                    }
                    m_tokens.push_back(Token{TokenType::kName, nameStr});
                } else {
                    std::cerr << "Error: unknown character at position " << m_scanPosition << std::endl;
                    return false;
                }
            }
        }

        return true;
    }

    Token nextToken() {
        if (m_currentTokenIndex < m_tokens.size()) {
            return m_tokens[m_currentTokenIndex++];
        }
        return Token{TokenType::kBlank, ""};
    }

private:
    std::istream& nextSymbol(char& symbol) {
        ++m_scanPosition;
        return m_input.get(symbol);
    }

    bool isNumber(std::string numberStr) {
        const char* numberCStr = numberStr.c_str();
        char* end;
        std::strtol(numberCStr, &end, 10);
        if (*numberCStr == '\0' || *end != '\0') {
            return false;
        }
        return true;
    }

    char skipLine() {
        char symbol;
        while (nextSymbol(symbol) && symbol != '\n') {}
        return symbol;
    }

private:
    size_t m_scanPosition = 0;
    std::vector<Token> m_tokens;
    size_t m_currentTokenIndex = 0;
    std::ifstream& m_input;
};

}  // namespace asm_compiler
