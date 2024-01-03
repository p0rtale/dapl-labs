#pragma once

#include <Clipl/Clipl/Type/Type.hpp>


namespace type {

class BasicType: public Type {
public:
    enum class InternalType {
        kInteger,
        kRealNumber,
        kPointer,
    };

public:
    BasicType() = default;

    virtual InternalType GetInternalType() const = 0;

    bool IsBasicType() const override {
        return true;
    }

    void SetConst() {
        m_IsMutable = false;
    }

    bool IsMutable() const {
        return m_IsMutable;
    }

    void SetVolatile() {
        m_IsVolatile = true;
    }

    bool IsVolatile() const {
        return m_IsVolatile;
    }

protected:
    bool m_IsMutable = true;
    bool m_IsVolatile = false;
};

}  // namespace type
