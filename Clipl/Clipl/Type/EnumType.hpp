#pragma once

#include <vector>

#include <Clipl/Clipl/Base.hpp>
#include <Clipl/Clipl/Type/ComplexType.hpp>
#include <Clipl/Clipl/Type/IntegerType.hpp>


namespace clipl::type {

class UnionType: public ComplexType {
public:
    UnionType(std::vector<RefT<IntegerType>> constants)
        : m_Constants(std::move(constants)) {}

    InternalType GetInternalType() const override {
        return InternalType::kEnum;
    }

    std::vector<RefT<IntegerType>> GetConstants() const {
        return m_Constants;
    }

private:
    std::vector<RefT<IntegerType>> m_Constants;
};

}  // namespace clipl::type
