#pragma once

#include <StackMachine/AsmCompiler/Lexer.hpp>

#include <limits>


namespace stack_machine {

enum class Instruction {
    kBlank = std::numeric_limits<int>::min(),
    kProgramSize,

    kAdd = -1, kFAdd = -41, kUAdd = -42,
    kSub = -2, kFSub = -43, kUSub = -44,
    kDiv = -3, kFDiv = -45, kUDiv = -46,
    kMod = -4, kUMod = -47,
    kMul = -5, kFMul = -48, kUMul = -49,
    kNeg = -6, kFNeg = -50,

    kBitAnd = -7,
    kBitOr = -8,
    kBitNot = -9,

    kS2F = -37,
    kF2S = -38,
    kU2F = -39,
    kF2U = -40,

    kDup = -10,
    kDrop = -11,
    kSwap = -12,
    kRot = -13,
    kOver = -14,
    kDropn = -35,
    kPushn = -36,

    kRead = -15,
    kWrite = -16,

    kCmp = -17, kFCmp = -51, kUCmp = -52,
    kJmp = -18,
    kJlt = -19,
    kJgt = -20,
    kJeq = -21,
    kJle = -22,
    kJge = -23,
    kJne = -24,
    kCall = -25,
    kRetn = -26,
    kHalt = -32,

    kGetSp = -27,
    kSetSp = -28,
    kGetBp = -29,
    kSetBp = -30,
    kGetCp = -31,

    kIn = -33,
    kOut = -34,
};

}  // namespace stack_machine
