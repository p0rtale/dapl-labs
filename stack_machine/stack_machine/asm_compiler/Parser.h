#pragma once

#include <stack_machine/asm_compiler/Lexer.h>
#include <stack_machine/asm_compiler/Instruction.h>

#include <vector>
#include <string>
#include <unordered_map>

namespace asm_compiler {

class Parser {
public:
    Parser() = default;

    bool parse(Lexer& lexer);

    std::vector<Instruction>& getInstructions();

    std::unordered_map<std::string, std::string>& getConstants();

private:
    std::vector<Instruction> m_instructions;
    std::unordered_map<std::string, std::string> m_constants;
};

}  // namespace asm_compiler
