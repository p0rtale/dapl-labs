#pragma once

#include <Clipl/Type/BasicType.hpp>


namespace clipl::type {

class VoidType: public BasicType {
public:
    VoidType() = default;

    InternalType GetInternalType() const override {
        return InternalType::kVoid;
    }
};

}  // namespace clipl::type
