#pragma once

#include <stack_machine/machine/MemoryContainer.h>

#include <vector>

namespace stack_machine {

class Stack {
public:
    Stack(MemoryContainer& memory, size_t maxSize, size_t& sp)
        : m_memory(memory), m_border(memory.size() - maxSize), m_sp(sp) {}

    Stack(const Stack& other) = delete;
    Stack(Stack&& other) = delete;

    Stack& operator=(const Stack& other) = delete;
    Stack& operator=(Stack&& other) = delete;

    ~Stack() = default;

    void push(Word word) {
        if (m_sp < m_border) {
            // ...
        }

        m_memory[--m_sp] = word;
    }

    Word pop() {
        return m_memory.at(m_sp++);
    }

private:
    MemoryContainer& m_memory;
    size_t m_border;
    size_t& m_sp;
};

}  // namespace stack_machine
