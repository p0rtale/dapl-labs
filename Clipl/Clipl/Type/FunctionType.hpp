#pragma once

#include <vector>

#include <Clipl/Base.hpp>
#include <Clipl/Type/Type.hpp>
#include <Clipl/Type/NodeType.hpp>


namespace clipl::type {

class FunctionType: public NodeType {
public:
    FunctionType() = default;

    FunctionType(std::vector<RefT<Type>> parameters)
        : m_Parameters(std::move(parameters)) {}

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
        return true;
    }

    std::vector<RefT<Type>> GetParameters() const {
        return m_Parameters;
    }

    void AttachType(RefT<NodeType> type) override {
        m_ReturnType = type;
    }

    RefT<Type> GetReturnType() const {
        return m_ReturnType;
    }

private:
    std::vector<RefT<Type>> m_Parameters;
    RefT<NodeType> m_ReturnType;
};

}  // namespace clipl::type
