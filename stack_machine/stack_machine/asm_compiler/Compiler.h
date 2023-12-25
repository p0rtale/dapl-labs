#pragma once

#include <stack_machine/machine/Instruction.h>
#include <stack_machine/asm_compiler/Parser.h>

#include <unordered_map>
#include <vector>
#include <string>

namespace asm_compiler {

static std::unordered_map<std::string, stack_machine::Instruction> instructionNameMap = {
    {"ADD",  stack_machine::Instruction::kAdd},
    {"FADD", stack_machine::Instruction::kFAdd},
    {"UADD", stack_machine::Instruction::kUAdd},
    {"SUB",  stack_machine::Instruction::kSub},
    {"FSUB", stack_machine::Instruction::kFSub},
    {"USUB", stack_machine::Instruction::kUSub},
    {"DIV",  stack_machine::Instruction::kDiv},
    {"FDIV", stack_machine::Instruction::kFDiv},
    {"UDIV", stack_machine::Instruction::kUDiv},
    {"MOD",  stack_machine::Instruction::kMod},
    {"UMOD", stack_machine::Instruction::kUMod},
    {"MUL",  stack_machine::Instruction::kMul},
    {"FMUL", stack_machine::Instruction::kFMul},
    {"UMUL", stack_machine::Instruction::kUMul},
    {"NEG",  stack_machine::Instruction::kNeg},
    {"FNEG", stack_machine::Instruction::kFNeg},

    {"BITAND", stack_machine::Instruction::kBitAnd},
    {"BITOR",  stack_machine::Instruction::kBitOr},
    {"BITNOT", stack_machine::Instruction::kBitNot},

    {"S2F", stack_machine::Instruction::kS2F},
    {"F2S", stack_machine::Instruction::kF2S},
    {"U2F", stack_machine::Instruction::kU2F},
    {"F2U", stack_machine::Instruction::kF2U},

    {"DUP",   stack_machine::Instruction::kDup},
    {"DROP",  stack_machine::Instruction::kDrop},
    {"SWAP",  stack_machine::Instruction::kSwap},
    {"ROT",   stack_machine::Instruction::kRot},
    {"OVER",  stack_machine::Instruction::kOver},
    {"DROPN", stack_machine::Instruction::kDropn},
    {"PUSHN", stack_machine::Instruction::kPushn},

    {"READ",  stack_machine::Instruction::kRead},
    {"WRITE", stack_machine::Instruction::kWrite},

    {"CMP",  stack_machine::Instruction::kCmp},
    {"FCMP", stack_machine::Instruction::kFCmp},
    {"UCMP", stack_machine::Instruction::kUCmp},
    {"JMP",  stack_machine::Instruction::kJmp},
    {"JLT",  stack_machine::Instruction::kJlt},
    {"JGT",  stack_machine::Instruction::kJgt},
    {"JEQ",  stack_machine::Instruction::kJeq},
    {"JLE",  stack_machine::Instruction::kJle},
    {"JGE",  stack_machine::Instruction::kJge},
    {"JNE",  stack_machine::Instruction::kJne},
    {"CALL", stack_machine::Instruction::kCall},
    {"RETN", stack_machine::Instruction::kRetn},
    {"HALT", stack_machine::Instruction::kHalt},

    {"GETSP", stack_machine::Instruction::kGetSp},
    {"SETSP", stack_machine::Instruction::kSetSp},
    {"GETBP", stack_machine::Instruction::kGetBp},
    {"SETBP", stack_machine::Instruction::kSetBp},
    {"GETCP", stack_machine::Instruction::kGetCp},

    {"IN",  stack_machine::Instruction::kIn},
    {"OUT", stack_machine::Instruction::kOut},
};

class Compiler {
public:
    Compiler(std::vector<std::string> filenames);

    bool compile();

    std::vector<std::string>& getMachineCode();

    void saveMachineCode(std::string filename);

private:
    std::vector<std::string> m_filenames;
    Parser m_parser;
    std::vector<std::string> m_machineCode;
};

}  // namespace asm_compiler
