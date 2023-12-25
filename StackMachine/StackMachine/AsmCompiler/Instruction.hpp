#pragma once

#include <string>

namespace asm_compiler {

enum class InstructionType {
    kAsperand,
    kName,
    kNumber,
};

struct Instruction {
    InstructionType type;
    std::string value;
};

}  // namespace asm_compiler
