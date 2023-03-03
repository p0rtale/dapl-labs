#pragma once

#include <stack_machine/asm_compiler/Lexer.h>
#include <stack_machine/asm_compiler/Parser.h>
#include <stack_machine/asm_compiler/Instruction.h>

#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>

namespace asm_compiler {

std::unordered_map<std::string, stack_machine::Instruction> instructionNameMap = {
    {"ADD", stack_machine::Instruction::kAdd},
    {"SUB", stack_machine::Instruction::kSub},
    {"DIV", stack_machine::Instruction::kDiv},
    {"MOD", stack_machine::Instruction::kMod},
    {"MUL", stack_machine::Instruction::kMul},
    {"NEG", stack_machine::Instruction::kNeg},

    {"BITAND", stack_machine::Instruction::kBitAnd},
    {"BITOR", stack_machine::Instruction::kBitOr},
    {"BITNOT", stack_machine::Instruction::kBitNot},

    {"DUP", stack_machine::Instruction::kDup},
    {"DROP", stack_machine::Instruction::kDrop},
    {"SWAP", stack_machine::Instruction::kSwap},
    {"ROT", stack_machine::Instruction::kRot},
    {"OVER", stack_machine::Instruction::kOver},
    {"DROPN", stack_machine::Instruction::kDropn},
    {"PUSHN", stack_machine::Instruction::kPushn},

    {"READ", stack_machine::Instruction::kRead},
    {"WRITE", stack_machine::Instruction::kWrite},

    {"CMP", stack_machine::Instruction::kCmp},
    {"JMP", stack_machine::Instruction::kJmp},
    {"JLT", stack_machine::Instruction::kJlt},
    {"JGT", stack_machine::Instruction::kJgt},
    {"JEQ", stack_machine::Instruction::kJeq},
    {"JLE", stack_machine::Instruction::kJle},
    {"JGE", stack_machine::Instruction::kJge},
    {"JNE", stack_machine::Instruction::kJne},
    {"CALL", stack_machine::Instruction::kCall},
    {"RETN", stack_machine::Instruction::kRetn},
    {"HALT", stack_machine::Instruction::kHalt},

    {"GETSP", stack_machine::Instruction::kGetSp},
    {"SETSP", stack_machine::Instruction::kSetSp},
    {"GETBP", stack_machine::Instruction::kGetBp},
    {"SETBP", stack_machine::Instruction::kSetBp},
    {"GETCP", stack_machine::Instruction::kGetCp},

    {"IN", stack_machine::Instruction::kIn},
    {"OUT", stack_machine::Instruction::kOut},
};

class Compiler {
public:
    Compiler(std::vector<std::string> filenames): m_filenames(filenames) {}

    bool compile() {
        for (const auto& filename: m_filenames) {
            std::ifstream input(filename);
            auto lexer = Lexer{input};
            bool ok = m_parser.parse(lexer);
            if (!ok) {
                return false;
            }
        }

        auto& instructions = m_parser.getInstructions();
        auto& constants = m_parser.getConstants();

        m_machineCode.clear();
        for (const auto& instruction: instructions) {
            if (instruction.type == InstructionType::kNumber) {
                m_machineCode.push_back(instruction.value);
            } else if (instruction.type == InstructionType::kAsperand) {
                m_machineCode.push_back(std::to_string(m_machineCode.size()));
            } else if (instruction.type == InstructionType::kName) {
                if (constants.contains(instruction.value)) {
                    m_machineCode.push_back(constants[instruction.value]);
                } else if (instructionNameMap.contains(instruction.value)) {
                    m_machineCode.push_back(std::to_string(static_cast<int>(instructionNameMap[instruction.value])));
                } else {
                    std::cerr << "Error: unknown constant name: " << instruction.value << std::endl;
                    return false;
                }
            }
        }

        return true;
    }

    std::vector<std::string>& getMachineCode() {
        return m_machineCode;
    }

    void saveMachineCode(std::string filename) {
        std::ofstream output(filename);
        for (auto word: m_machineCode) {
            output << word << "\n";
        }
    }

private:
    std::vector<std::string> m_filenames;
    Parser m_parser;
    std::vector<std::string> m_machineCode;
};

}  // namespace asm_compiler
