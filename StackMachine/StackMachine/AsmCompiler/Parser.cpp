#include <StackMachine/AsmCompiler/Parser.hpp>

#include <iostream>

namespace asm_compiler {

bool Parser::parse(Lexer& lexer) {
    bool ok = lexer.scan();
    if (!ok) {
        return false;
    }

    auto token = lexer.nextToken();
    while (!token.isEmpty()) {
        if (token.type == TokenType::kNumber) {
            m_instructions.push_back(Instruction{InstructionType::kNumber, token.value});
        } else if (token.type == TokenType::kName) {
            m_instructions.push_back(Instruction{InstructionType::kName, token.value});
        } else if (token.type == TokenType::kAsperand) {
            m_instructions.push_back(Instruction{InstructionType::kAsperand, token.value});
        } else if (token.type == TokenType::kColon) {
            token = lexer.nextToken();
            if (token.type != TokenType::kName) {
                std::cerr << "Error: incorrect constant definition" << std::endl;
                return false;
            }
            std::string constantName = token.value;

            token = lexer.nextToken();
            if (token.type != TokenType::kEqual) {
                m_constants[constantName] = std::to_string(m_instructions.size());
                continue;
            }

            token = lexer.nextToken();
            if (token.type == TokenType::kNumber) {
                m_constants[constantName] = token.value;
            } else if (token.type == TokenType::kName) {
                std::string prevConstantName = token.value;
                if (m_constants.contains(prevConstantName)) {
                    m_constants[constantName] = prevConstantName;
                } else {
                    std::cerr << "Error: unknown constant name: " << prevConstantName << std::endl;
                    return false;
                }
            } else if (token.type == TokenType::kAsperand) {
                m_constants[constantName] = std::to_string(m_instructions.size());
            } else {
                std::cerr << "Error: incorrect term: " << token.value << std::endl;
                return false;
            }
        } else if (token.type == TokenType::kEqual) {
            std::cerr << "Error: '=' outside the constant definition" << std::endl;
            return false;
        }

        token = lexer.nextToken();
    }

    return true;
}

std::vector<Instruction>& Parser::getInstructions() {
    return m_instructions;
}

std::unordered_map<std::string, std::string>& Parser::getConstants() {
    return m_constants;
}
    
}  // namespace asm_compiler
