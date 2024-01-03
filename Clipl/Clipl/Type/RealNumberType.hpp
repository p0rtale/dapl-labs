#pragma once

#include <Clipl/Clipl/Type/BasicType.hpp>


namespace type {

class RealNumberType: public BasicType {
public:
    enum class TypeSpecifier {
        kFloat,
        kDouble,
    };

public:
    RealNumberType() = default;

    InternalType GetInternalType() const override {
        return InternalType::kRealNumber;
    }

    TypeSpecifier GetTypeSpecifier() const {
        return m_TypeSpecifier;
    }

    void SetTypeSpecifier(TypeSpecifier typeSpecifier) {
        m_TypeSpecifier = typeSpecifier;
    }

private:
    TypeSpecifier m_TypeSpecifier = TypeSpecifier::kFloat;
};

}  // namespace type
