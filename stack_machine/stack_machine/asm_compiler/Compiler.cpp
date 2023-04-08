#include <stack_machine/asm_compiler/Compiler.h>

#include <stack_machine/asm_compiler/Lexer.h>

namespace asm_compiler {

Compiler::Compiler(std::vector<std::string> filenames): m_filenames(filenames) {}

bool Compiler::compile() {
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

std::vector<std::string>& Compiler::getMachineCode() {
    return m_machineCode;
}

void Compiler::saveMachineCode(std::string filename) {
    std::ofstream output(filename);
    for (auto word: m_machineCode) {
        output << word << "\n";
    }
}

}  // namespace asm_compiler
