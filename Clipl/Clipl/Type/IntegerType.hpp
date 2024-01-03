#pragma once

#include <Clipl/Clipl/Type/BasicType.hpp>


namespace type {

class IntegerType: public BasicType {
public:
    enum class TypeSpecifier {
        kChar,
        kShort,
        kInt,
        kLong,
    };

public:
    IntegerType() = default;

    InternalType GetInternalType() const override {
        return InternalType::kInteger;
    }

    TypeSpecifier GetTypeSpecifier() const {
        return m_TypeSpecifier;
    }

    void SetTypeSpecifier(TypeSpecifier typeSpecifier) {
        m_TypeSpecifier = typeSpecifier;
    }

    void SetUnsigned() {
        m_IsSigned = false;
    }

    bool IsSigned() const {
        return m_IsSigned;
    }

private:
    bool m_IsSigned = true;

    TypeSpecifier m_TypeSpecifier = TypeSpecifier::kInt;
};

}  // namespace type
