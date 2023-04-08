#pragma once

#include <vector>
#include <fstream>

namespace stack_machine {

using Word = int;

class MemoryContainer {
public:
    explicit MemoryContainer(size_t cellsNumber);
    explicit MemoryContainer(std::ifstream& file);

    MemoryContainer(const MemoryContainer& other) = default;
    MemoryContainer(MemoryContainer&& other) = default;

    MemoryContainer& operator=(const MemoryContainer& other) = default;
    MemoryContainer& operator=(MemoryContainer&& other) = default;

    ~MemoryContainer() = default;

    Word& at(Word index);
    Word& operator[](Word index);

    size_t size() const;

    std::vector<Word>& data();
    const std::vector<Word>& data() const;

private:
    void fill(std::ifstream& file);

private:
    std::vector<Word> m_memoryCells;
};

}  // namespace stack_machine
