#pragma once

#include <vector>

#include <Clipl/Base.hpp>
#include <Clipl/Type/Type.hpp>
#include <Clipl/Type/NodeType.hpp>


namespace clipl::type {

class ArrayType: public NodeType {
public:
    ArrayType(RefT<ConstantExpression> size)
        : m_Size(size) {}

    bool IsBasicType() const override {
        return false;
    }

    bool IsPointerType() const override {
        return false;
    }

    bool IsArrayType() const override {
        return true;
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

    RefT<ConstantExpression> GetSize() const {
        return m_Size;
    }

private:
    RefT<NodeType> m_SubType;
    RefT<ConstantExpression> m_Size;
};

}  // namespace clipl::type
