#pragma once

#include <Clipl/Type/BasicType.hpp>


namespace clipl::type {

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

}  // namespace clipl::type
