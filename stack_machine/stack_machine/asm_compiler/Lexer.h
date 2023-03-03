#pragma once

#include <string>
#include <vector>

namespace asm_compiler {

enum class TokenType {
    kBlank,
    kMinus,
    kPlus,
    kLeftBracket,
    kRightBracket,
    kAsperand,
    kColon,
    kEqual,
    kDigit,
    kLetter,
};

struct Token {
    bool isEmpty() {
        return type == TokenType::kBlank;
    }

    TokenType type;
    char value;
};

class Lexer {
public:
    Lexer(std::ifstream& input): m_input(input) {}

    void scan() {
        char symbol;
        while (m_input.get(symbol)) {
            if (symbol == ';') {
                symbol = skipLine();
            }

            switch (symbol) {
            case '+':
                tokens.push_back(Token{TokenType::kPlus, symbol});
                break;
            case '-':
                tokens.push_back(Token{TokenType::kMinus, symbol});
                break;
            case '(':
                tokens.push_back(Token{TokenType::kLeftBracket, symbol});
                break;
            case ')':
                tokens.push_back(Token{TokenType::kRightBracket, symbol});
                break;
            case '@':
                tokens.push_back(Token{TokenType::kAsperand, symbol});
                break;
            case ':':
                tokens.push_back(Token{TokenType::kColon, symbol});
                break;
            case '=':
                tokens.push_back(Token{TokenType::kEqual, symbol});
                break;
            default:
                if (std::isdigit(symbol)) {
                    tokens.push_back(Token{TokenType::kDigit, symbol});
                } else if (std::isalpha(symbol) || symbol == '_') {
                    tokens.push_back(Token{TokenType::kLetter, symbol});
                }
            }
        }
    }

    Token nextToken() {
        if (currentTokenIndex < tokens.size()) {
            return tokens[currentTokenIndex++];
        }
        return Token{TokenType::kBlank, ' '}
    }

private:
    char skipLine() {
        char symbol;
        while (m_input.get(symbol) && symbol != '\n') {}
        return symbol;
    }

private:
    std::vector<Token> tokens;
    size_t currentTokenIndex = 0;
    std::ifstream& m_input;
};

}  // namespace asm_compiler
