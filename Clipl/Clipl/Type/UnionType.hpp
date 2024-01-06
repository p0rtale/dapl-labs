#pragma once

#include <vector>

#include <Clipl/Base.hpp>
#include <Clipl/Type/ComplexType.hpp>


namespace clipl::type {

class UnionType: public ComplexType {
public:
    UnionType() = default;

    UnionType(std::vector<RefT<Type>> fields)
        : m_Fields(std::move(fields)) {}

    InternalType GetInternalType() const override {
        return InternalType::kUnion;
    }

    std::vector<RefT<Type>> GetFields() const {
        return m_Fields;
    }

private:
    std::vector<RefT<Type>> m_Fields;
};

}  // namespace clipl::type
