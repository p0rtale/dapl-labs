#pragma once

#include <string>

namespace asm_compiler {

enum class TokenType {
    kBlank,
    kAsperand,
    kColon,
    kEqual,
    kName,
    kNumber,
};

struct Token {
    bool isEmpty() {
        return type == TokenType::kBlank;
    }

    TokenType type;
    std::string value;
};

}  // namespace asm_compiler
