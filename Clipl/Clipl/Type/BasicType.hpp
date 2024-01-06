#pragma once

#include <Clipl/Type/Type.hpp>


namespace clipl::type {

class BasicType: public Type {
public:
    enum class InternalType {
        kVoid,
        kInteger,
        kRealNumber,
    };

public:
    BasicType() = default;

    virtual InternalType GetInternalType() const = 0;

    bool IsBasicType() const override {
        return true;
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

    void SetConst() {
        m_IsConst = true;
    }

    bool IsConst() const {
        return m_IsConst;
    }

    void SetVolatile() {
        m_IsVolatile = true;
    }

    bool IsVolatile() const {
        return m_IsVolatile;
    }

protected:
    bool m_IsConst = false;
    bool m_IsVolatile = false;
};

}  // namespace clipl::type
