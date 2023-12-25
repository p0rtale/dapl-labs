#include <StackMachine/Machine/InstructionExecutor.hpp>

#include <array>
#include <cstdint>


namespace stack_machine {
    
InstructionExecutor::InstructionExecutor(Instruction instruction, Memory& memory, Registers& registers,
                    std::istream& input, std::ostream& output)
        : m_instruction(instruction), m_memory(memory), m_stack(m_memory.stack()), m_registers(registers),
            m_input(input), m_output(output) {}

void InstructionExecutor::execute() {
    switch (m_instruction) {
        case Instruction::kBlank: return;
        case Instruction::kAdd:  std::cout << "ADD\n";  return executeAdd();
        case Instruction::kFAdd: std::cout << "FADD\n"; return executeFAdd();
        case Instruction::kUAdd: std::cout << "UADD\n"; return executeUAdd();
        case Instruction::kSub:  std::cout << "SUB\n";  return executeSub();
        case Instruction::kFSub: std::cout << "FSUB\n"; return executeFSub();
        case Instruction::kUSub: std::cout << "USUB\n"; return executeUSub();
        case Instruction::kDiv:  std::cout << "DIV\n";  return executeDiv();
        case Instruction::kFDiv: std::cout << "FDIV\n"; return executeFDiv();
        case Instruction::kUDiv: std::cout << "UDIV\n"; return executeUDiv();
        case Instruction::kMod:  std::cout << "MOD\n";  return executeMod();
        case Instruction::kUMod: std::cout << "UMOD\n"; return executeUMod();
        case Instruction::kMul:  std::cout << "MUL\n";  return executeMul();
        case Instruction::kFMul: std::cout << "FMUL\n"; return executeFMul();
        case Instruction::kUMul: std::cout << "UMUL\n"; return executeUMul();
        case Instruction::kNeg:  std::cout << "NEG\n";  return executeNeg();
        case Instruction::kFNeg: std::cout << "FNEG\n"; return executeFNeg();

        case Instruction::kBitAnd: return executeAnd();
        case Instruction::kBitOr:  return executeOr();
        case Instruction::kBitNot: return executeNot();

        case Instruction::kS2F: return executeS2F();
        case Instruction::kF2S: return executeF2S();
        case Instruction::kU2F: return executeU2F();
        case Instruction::kF2U: return executeF2U();

        case Instruction::kDup:  std::cout << "DUP\n"; return executeDup();
        case Instruction::kDrop: std::cout << "DROP\n"; return executeDrop();
        case Instruction::kSwap: std::cout << "SWAP\n"; return executeSwap();
        case Instruction::kRot:  std::cout << "ROT\n"; return executeRot();
        case Instruction::kOver: std::cout << "OVER\n"; return executeOver();
        case Instruction::kDropn: std::cout << "DROPN\n"; return executeDropn();
        case Instruction::kPushn: std::cout << "PUSHN\n"; return executePushn();

        case Instruction::kRead: std::cout << "READ\n";  return executeRead();
        case Instruction::kWrite: std::cout << "WRITE\n"; return executeWrite();

        case Instruction::kCmp:  std::cout << "CMP\n"; return executeCmp();
        case Instruction::kJmp: std::cout << "JMP\n";  return executeJmp();
        case Instruction::kJlt: std::cout << "JLT\n"; return executeJlt();
        case Instruction::kJgt: std::cout << "JGT\n"; return executeJgt();
        case Instruction::kJeq: std::cout << "JEQ\n"; return executeJeq();
        case Instruction::kJle: std::cout << "JLE\n"; return executeJle();
        case Instruction::kJge: std::cout << "JGE\n"; return executeJge();
        case Instruction::kJne: std::cout << "JNE\n"; return executeJne();
        case Instruction::kCall: std::cout << "CALL\n"; return executeCall();
        case Instruction::kRetn: std::cout << "RETN\n"; return executeRetn();
        case Instruction::kHalt: std::cout << "HALT\n"; return executeHalt();

        case Instruction::kGetSp: std::cout << "GETSP\n"; return executeGetSp();
        case Instruction::kSetSp: std::cout << "SETSP\n"; return executeSetSp();
        case Instruction::kGetBp: std::cout << "GETBP\n"; return executeGetBp();
        case Instruction::kSetBp: std::cout << "SETBP\n"; return executeSetBp();
        case Instruction::kGetCp: std::cout << "GETCP\n"; return executeGetCp();

        case Instruction::kIn: std::cout << "IN\n"; return executeIn();
        case Instruction::kOut: std::cout << "OUT\n"; return executeOut();

        default: return executePush(static_cast<Word>(m_instruction));
    }
}

Word InstructionExecutor::getHaltResult() {
    if (isHalted) {
        return m_stack.pop();
    }
    return Word{0};
}

void InstructionExecutor::executeAdd() {
    Word second = m_stack.pop();
    Word first = m_stack.pop();
    m_stack.push(first + second);
}

void InstructionExecutor::executeFAdd() {
    Word second = m_stack.pop();
    float secondF = reinterpret_cast<float&>(second);
    Word first = m_stack.pop();
    float firstF = reinterpret_cast<float&>(first);
    float resultF = firstF + secondF;
    m_stack.push(reinterpret_cast<Word&>(resultF));
}

void InstructionExecutor::executeUAdd() {
    Word second = m_stack.pop();
    uint32_t secondU = reinterpret_cast<uint32_t&>(second);
    Word first = m_stack.pop();
    uint32_t firstU = reinterpret_cast<uint32_t&>(first);
    uint32_t resultU = firstU + secondU;
    m_stack.push(reinterpret_cast<Word&>(resultU));
}

void InstructionExecutor::executeSub() {
    Word second = m_stack.pop();
    Word first = m_stack.pop();
    m_stack.push(first - second);
}

void InstructionExecutor::executeFSub() {
    Word second = m_stack.pop();
    float secondF = reinterpret_cast<float&>(second);
    Word first = m_stack.pop();
    float firstF = reinterpret_cast<float&>(first);
    float resultF = firstF - secondF;
    m_stack.push(reinterpret_cast<Word&>(resultF));
}

void InstructionExecutor::executeUSub() {
    Word second = m_stack.pop();
    uint32_t secondU = reinterpret_cast<uint32_t&>(second);
    Word first = m_stack.pop();
    uint32_t firstU = reinterpret_cast<uint32_t&>(first);
    uint32_t resultU = firstU - secondU;
    m_stack.push(reinterpret_cast<Word&>(resultU));
}

void InstructionExecutor::executeDiv() {
    Word second = m_stack.pop();
    Word first = m_stack.pop();
    m_stack.push(first / second);
}

void InstructionExecutor::executeFDiv() {
    Word second = m_stack.pop();
    float secondF = reinterpret_cast<float&>(second);
    Word first = m_stack.pop();
    float firstF = reinterpret_cast<float&>(first);
    float resultF = firstF / secondF;
    m_stack.push(reinterpret_cast<Word&>(resultF));
}

void InstructionExecutor::executeUDiv() {
    Word second = m_stack.pop();
    uint32_t secondU = reinterpret_cast<uint32_t&>(second);
    Word first = m_stack.pop();
    uint32_t firstU = reinterpret_cast<uint32_t&>(first);
    uint32_t resultU = firstU / secondU;
    m_stack.push(reinterpret_cast<Word&>(resultU));
}

void InstructionExecutor::executeMod() {
    Word second = m_stack.pop();
    Word first = m_stack.pop();
    m_stack.push(first % second);
}

void InstructionExecutor::executeUMod() {
    Word second = m_stack.pop();
    uint32_t secondU = reinterpret_cast<uint32_t&>(second);
    Word first = m_stack.pop();
    uint32_t firstU = reinterpret_cast<uint32_t&>(first);
    uint32_t resultU = firstU % secondU;
    m_stack.push(reinterpret_cast<Word&>(resultU));
}

void InstructionExecutor::executeMul() {
    Word second = m_stack.pop();
    Word first = m_stack.pop();
    m_stack.push(first * second);
}

void InstructionExecutor::executeFMul() {
    Word second = m_stack.pop();
    float secondF = reinterpret_cast<float&>(second);
    Word first = m_stack.pop();
    float firstF = reinterpret_cast<float&>(first);
    float resultF = firstF * secondF;
    m_stack.push(reinterpret_cast<Word&>(resultF));
}

void InstructionExecutor::executeUMul() {
    Word second = m_stack.pop();
    uint32_t secondU = reinterpret_cast<uint32_t&>(second);
    Word first = m_stack.pop();
    uint32_t firstU = reinterpret_cast<uint32_t&>(first);
    uint32_t resultU = firstU * secondU;
    m_stack.push(reinterpret_cast<Word&>(resultU));
}

void InstructionExecutor::executeNeg() {
    Word word = m_stack.pop();
    m_stack.push(-word);
}

void InstructionExecutor::executeFNeg() {
    Word word = m_stack.pop();
    float wordF = reinterpret_cast<float&>(word);
    float resultF = -wordF;
    m_stack.push(reinterpret_cast<Word&>(resultF));
}

void InstructionExecutor::executeAnd() {
    Word second = m_stack.pop();
    Word first = m_stack.pop();
    m_stack.push(first & second);
}

void InstructionExecutor::executeOr() {
    Word second = m_stack.pop();
    Word first = m_stack.pop();
    m_stack.push(first | second);
}

void InstructionExecutor::executeNot() {
    Word word = m_stack.pop();
    m_stack.push(~word);
}

void InstructionExecutor::executeS2F() {
    Word wordS = m_stack.pop();
    float tempF = static_cast<float>(wordS);
    Word wordF = reinterpret_cast<Word&>(tempF);
    m_stack.push(wordF);
}

void InstructionExecutor::executeF2S() {
    Word wordF = m_stack.pop();
    float tempF = reinterpret_cast<float&>(wordF);
    Word wordS = static_cast<Word>(tempF);
    m_stack.push(wordS);
}

void InstructionExecutor::executeU2F() {
    Word wordU = m_stack.pop();
    uint32_t tempU = reinterpret_cast<uint32_t&>(wordU);
    float tempF = static_cast<float>(tempU);
    Word wordF = reinterpret_cast<Word&>(tempF);
    m_stack.push(wordF);
}

void InstructionExecutor::executeF2U() {
    Word wordF = m_stack.pop();
    float tempF = reinterpret_cast<float&>(wordF);
    uint32_t tempU = static_cast<uint32_t>(tempF);
    Word wordU = reinterpret_cast<Word&>(tempU);
    m_stack.push(wordU);
}

void InstructionExecutor::executeDup() {
    Word word = m_stack.pop();
    m_stack.push(word);
    m_stack.push(word);
}

void InstructionExecutor::executeDrop() {
    m_stack.pop();
}

void InstructionExecutor::executeSwap() {
    Word second = m_stack.pop();
    Word first = m_stack.pop();
    m_stack.push(second);
    m_stack.push(first);
}

void InstructionExecutor::executeRot() {
    Word third = m_stack.pop();
    Word second = m_stack.pop();
    Word first = m_stack.pop();
    m_stack.push(second);
    m_stack.push(third);
    m_stack.push(first);
}

void InstructionExecutor::executeOver() {
    Word second = m_stack.pop();
    Word first = m_stack.pop();
    m_stack.push(first);
    m_stack.push(second);
    m_stack.push(first);
}

void InstructionExecutor::executeDropn() {
    Word number = m_stack.pop();
    for (; number > 0; --number) {
        m_stack.pop();
    }
}

void InstructionExecutor::executePushn() {
    Word number = m_stack.pop();
    for (; number > 0; --number) {
        m_stack.push(0);
    }
}

void InstructionExecutor::executeRead() {
    Word address = m_stack.pop();
    Word cell = m_memory.readCell(address);
    m_stack.push(cell);
}

void InstructionExecutor::executeWrite() {
    Word value = m_stack.pop();
    Word address = m_stack.pop();
    m_memory.writeCell(address, value);
}

void InstructionExecutor::executeCmp() {
    Word second = m_stack.pop();
    Word first = m_stack.pop();
    
    Word result = 1;
    if (first < second) {
        result = -1;
    } else if (first == second) {
        result = 0;
    }

    m_stack.push(result);       
}

void InstructionExecutor::executeFCmp() {
    Word second = m_stack.pop();
    float secondF = reinterpret_cast<float&>(second);
    Word first = m_stack.pop();
    float firstF = reinterpret_cast<float&>(first);
    
    Word result = 1;
    if (firstF < secondF) {
        result = -1;
    } else if (firstF == secondF) {  // |firstF - secondF| < eps ?
        result = 0;
    }

    m_stack.push(result);       
}

void InstructionExecutor::executeUCmp() {
    Word second = m_stack.pop();
    float secondU = reinterpret_cast<uint32_t&>(second);
    Word first = m_stack.pop();
    float firstU = reinterpret_cast<uint32_t&>(first);
    
    Word result = 1;
    if (firstU < secondU) {
        result = -1;
    } else if (firstU == secondU) {
        result = 0;
    }

    m_stack.push(result);       
}

void InstructionExecutor::executeJmp() {
    Word address = m_stack.pop();
    m_registers.m_cp = address;
}

void InstructionExecutor::executeJlt() {
    Word address = m_stack.pop();
    Word value = m_stack.pop();
    if (value < 0) {
        m_registers.m_cp = address;  
    }
}

void InstructionExecutor::executeJgt() {
    Word address = m_stack.pop();
    Word value = m_stack.pop();
    if (value > 0) {
        m_registers.m_cp = address;  
    }
}

void InstructionExecutor::executeJeq() {
    Word address = m_stack.pop();
    Word value = m_stack.pop();
    if (value == 0) {
        m_registers.m_cp = address;  
    }
}

void InstructionExecutor::executeJle() {
    Word address = m_stack.pop();
    Word value = m_stack.pop();
    if (value <= 0) {
        m_registers.m_cp = address;  
    }
}

void InstructionExecutor::executeJge() {
    Word address = m_stack.pop();
    Word value = m_stack.pop();
    if (value >= 0) {
        m_registers.m_cp = address;  
    }
}

void InstructionExecutor::executeJne() {
    Word address = m_stack.pop();
    Word value = m_stack.pop();
    if (value != 0) {
        m_registers.m_cp = address;  
    }
}

void InstructionExecutor::executeCall() {
    Word address = m_stack.pop();
    m_stack.push(m_registers.m_cp);
    m_registers.m_cp = address;
}

void InstructionExecutor::executeRetn() {
    Word number = m_stack.pop();
    Word address = m_stack.pop();
    m_registers.m_cp = address;
    for (; number > 0; --number) {
        m_stack.pop();
    }
}

void InstructionExecutor::executeHalt() {
    isHalted = true;
}

void InstructionExecutor::executeGetSp() {
    m_stack.push(m_registers.m_sp);
}

void InstructionExecutor::executeSetSp() {
    m_registers.m_sp = m_stack.pop();
}

void InstructionExecutor::executeGetBp() {
    m_stack.push(m_registers.m_bp);
}

void InstructionExecutor::executeSetBp() {
    m_registers.m_bp = m_stack.pop();
}

void InstructionExecutor::executeGetCp() {
    m_stack.push(m_registers.m_cp);
}

void InstructionExecutor::executeIn() {
    unsigned int codepoint = 0;

    std::array<unsigned char, 5> bytes = { 0x00, 0x00, 0x00, 0x00 };
    m_input >> bytes[0];

    if ((0x80 & bytes[0]) == 0x00) {
        codepoint = bytes[0];
    } else if ((0xE0 & bytes[0]) == 0xC0) {
        m_input >> bytes[1];
        codepoint += ((bytes[0] & 0x1F) << 6) + (bytes[1] & 0x3F);
    } else if ((0xF0 & bytes[0]) == 0xE0) {
        m_input >> bytes[1] >> bytes[2];
        codepoint += ((bytes[0] & 0x0F) << 12) + ((bytes[1] & 0x3F) << 6) + (bytes[2] & 0x3F);
    } else if ((0xF8 & bytes[0]) == 0xF0 && bytes[0] <= 0xF4) {
        m_input >> bytes[1] >> bytes[2] >> bytes[3];
        codepoint += ((bytes[0] & 0x07) << 18) + ((bytes[1] & 0x3F) << 12) + ((bytes[2] & 0x3F) << 6) + (bytes[3] & 0x3F);
    }

    m_stack.push(codepoint);
}

void InstructionExecutor::executeOut() {
    unsigned int codepoint = m_stack.pop();

    std::array<char, 5> bytes = { 0x00, 0x00, 0x00, 0x00, 0x00 };
    if (codepoint <= 0x7F) {
        bytes[0] = codepoint;
    } else if (codepoint <= 0x7FF) {
        bytes[0] = (codepoint >> 6) + 0b11000000;
        bytes[1] = (codepoint & 0b111111) + 0b10000000;
    } else if (codepoint <= 0xFFFF) {
        bytes[0] = (codepoint >> 12) + 0b11100000;
        bytes[1] = ((codepoint >> 6) & 0b111111) + 0b10000000;
        bytes[2] = (codepoint & 0b111111) + 0b10000000;
    } else if (codepoint <= 0x10FFFF) {
        bytes[0] = (codepoint >> 18) + 0b11110000;
        bytes[1] = ((codepoint >> 12) & 0b111111) + 0b10000000;
        bytes[2] = ((codepoint >> 6) & 0b111111) + 0b10000000;
        bytes[3] = (codepoint & 0b111111) + 0b10000000;
    }

    m_output << bytes.data();
}

void InstructionExecutor::executePush(Word code) {
    if (code >= 0) {
        m_stack.push(code);
    }
}

}  // namespace stack_machine
