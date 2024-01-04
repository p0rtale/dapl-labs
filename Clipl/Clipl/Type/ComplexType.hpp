#pragma once

#include <Clipl/Type/Type.hpp>


namespace clipl::type {

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

}  // namespace clipl::type
