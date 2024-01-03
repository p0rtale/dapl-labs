#pragma once

#include <Clipl/Clipl/Type/Type.hpp>


namespace type {

class ComplexType: public Type {
public:
    enum class InternalType {
        kArray,
        kStruct,
        kUnion,
        kEnum,
    };

public:
    ComplexType() = default;

    virtual InternalType GetInternalType() const = 0;
};

}  // namespace type
