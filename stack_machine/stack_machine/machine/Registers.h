#pragma once

#include <cstddef>

namespace stack_machine {

struct Registers {
    size_t m_cp = 0;
    size_t m_sp = 0;
    size_t m_bp = 0;
};

}  // namespace stack_machine
