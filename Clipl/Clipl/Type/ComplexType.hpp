#pragma once

#include <Clipl/Type/Type.hpp>


namespace clipl::type {

class ComplexType: public Type {
public:
    enum class InternalType {
        kStruct,
        kUnion,
        kEnum,
    };

public:
    ComplexType() = default;

    bool IsBasicType() const override {
        return false;
    }

    bool IsPointerType() const override {
        return false;
    }

    bool IsArrayType() const override {
        return false;
    }

    bool IsFunctionType() const override {
        return false;
    }

    virtual InternalType GetInternalType() const = 0;
};

}  // namespace clipl::type
