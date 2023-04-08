#include <stack_machine/machine/InstructionExecutor.h>

#include <array>


namespace stack_machine {
    
InstructionExecutor::InstructionExecutor(Instruction instruction, Memory& memory, Registers& registers,
                    std::istream& input, std::ostream& output)
        : m_instruction(instruction), m_memory(memory), m_stack(m_memory.stack()), m_registers(registers),
            m_input(input), m_output(output) {}

void InstructionExecutor::execute() {
    switch (m_instruction) {
        case Instruction::kBlank: return;
        case Instruction::kAdd: return executeAdd();
        case Instruction::kSub: return executeSub();
        case Instruction::kDiv: return executeDiv();
        case Instruction::kMod: return executeMod();
        case Instruction::kMul: return executeMul();
        case Instruction::kNeg: return executeNeg();

        case Instruction::kBitAnd: return executeAnd();
        case Instruction::kBitOr:  return executeOr();
        case Instruction::kBitNot: return executeNot();

        case Instruction::kDup:   return executeDup();
        case Instruction::kDrop:  return executeDrop();
        case Instruction::kSwap:  return executeSwap();
        case Instruction::kRot:   return executeRot();
        case Instruction::kOver:  return executeOver();
        case Instruction::kDropn: return executeDropn();
        case Instruction::kPushn: return executePushn();

        case Instruction::kRead:  return executeRead();
        case Instruction::kWrite: return executeWrite();

        case Instruction::kCmp:  return executeCmp();
        case Instruction::kJmp:  return executeJmp();
        case Instruction::kJlt:  return executeJlt();
        case Instruction::kJgt:  return executeJgt();
        case Instruction::kJeq:  return executeJeq();
        case Instruction::kJle:  return executeJle();
        case Instruction::kJge:  return executeJge();
        case Instruction::kJne:  return executeJne();
        case Instruction::kCall: return executeCall();
        case Instruction::kRetn: return executeRetn();
        case Instruction::kHalt: return;

        case Instruction::kGetSp: return executeGetSp();
        case Instruction::kSetSp: return executeSetSp();
        case Instruction::kGetBp: return executeGetBp();
        case Instruction::kSetBp: return executeSetBp();
        case Instruction::kGetCp: return executeGetCp();

        case Instruction::kIn:  return executeIn();
        case Instruction::kOut: return executeOut();

        default: return executePush(static_cast<Word>(m_instruction));
    }
}

void InstructionExecutor::executeAdd() {
    Word second = m_stack.pop();
    Word first = m_stack.pop();
    m_stack.push(first + second);
}

void InstructionExecutor::executeSub() {
    Word second = m_stack.pop();
    Word first = m_stack.pop();
    m_stack.push(first - second);
}

void InstructionExecutor::executeDiv() {
    Word second = m_stack.pop();
    Word first = m_stack.pop();
    m_stack.push(first / second);
}

void InstructionExecutor::executeMod() {
    Word second = m_stack.pop();
    Word first = m_stack.pop();
    m_stack.push(first % second);
}

void InstructionExecutor::executeMul() {
    Word second = m_stack.pop();
    Word first = m_stack.pop();
    m_stack.push(first * second);
}

void InstructionExecutor::executeNeg() {
    Word word = m_stack.pop();
    m_stack.push(-word);
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
    Word address = m_stack.pop();
    executeDropn();
    m_registers.m_cp = address;
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
