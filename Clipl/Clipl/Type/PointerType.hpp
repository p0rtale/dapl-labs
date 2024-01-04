#pragma once

#include <Clipl/Base.hpp>
#include <Clipl/Type/Type.hpp>
#include <Clipl/Type/BasicType.hpp>


namespace clipl::type {

class PointerType: public BasicType {
public:
    PointerType(RefT<Type> subType)
        : m_SubType(subType) {}

    InternalType GetInternalType() const override {
        return InternalType::kPointer;
    }

    RefT<Type> GetSubType() const {
        return m_SubType;
    }

private:
    RefT<Type> m_SubType;
};

}  // namespace clipl::type
