#pragma once

#include <Clipl/Base.hpp>
#include <Clipl/Type/Type.hpp>
#include <Clipl/Type/NodeType.hpp>


namespace clipl::type {

class PointerType: public NodeType {
public:
    PointerType(bool isConst, bool isVolatile)
        : m_IsConst(isConst), m_IsVolatile(isVolatile) {}


    bool IsBasicType() const override {
        return false;
    }

    bool IsPointerType() const override {
        return true;
    }

    bool IsArrayType() const override {
        return false;
    }

    bool IsFunctionType() const override {
        return false;
    }

    void AttachType(RefT<NodeType> type) override {
        m_SubType = type;
    }

    RefT<Type> GetSubType() const {
        return m_SubType;
    }

private:
    RefT<NodeType> m_SubType;

    bool m_IsConst = false;
    bool m_IsVolatile = false;
};

}  // namespace clipl::type
