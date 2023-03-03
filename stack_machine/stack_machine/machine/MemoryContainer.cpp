#include <StackMachine/Machine/MemoryContainer.h>

namespace stack_machine {

MemoryContainer::MemoryContainer(size_t cellsNumber): m_memoryCells(cellsNumber) {}

MemoryContainer::MemoryContainer(std::ifstream& file) {
    fill(file);
}

Word& MemoryContainer::at(Word index) {
    return m_memoryCells.at(index);
}

Word& MemoryContainer::operator[](Word index) {
    return m_memoryCells[index];
}

size_t MemoryContainer::size() const {
    return m_memoryCells.size();
}

std::vector<Word>& MemoryContainer::data() {
    return m_memoryCells;
}

const std::vector<Word>& MemoryContainer::data() const {
    return m_memoryCells;
}

void MemoryContainer::fill(std::ifstream& file) {
    m_memoryCells.clear();
    m_memoryCells.reserve(128);

    Word word;
    while (file >> word) {
        m_memoryCells.push_back(word);
    }
}

}  // namespace stack_machine
