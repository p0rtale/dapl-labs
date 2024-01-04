#pragma once

#include <vector>

#include <Clipl/Base.hpp>
#include <Clipl/Type/ComplexType.hpp>


namespace clipl::type {

class ArrayType: public ComplexType {
public:
    ArrayType(std::vector<RefT<Type>> elements, size_t size)
        : m_Elements(elements), m_Size(size) {}

    InternalType GetInternalType() const override {
        return InternalType::kArray;
    }

    size_t GetSize() const {
        return m_Size;
    }

    std::vector<RefT<Type>> GetElements() const {
        return m_Elements;
    }

private:
    std::vector<RefT<Type>> m_Elements;
    size_t m_Size = 0;
};

}  // namespace clipl::type
