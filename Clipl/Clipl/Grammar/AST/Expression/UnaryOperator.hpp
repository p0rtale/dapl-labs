#pragma once

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>


namespace ast {

class UnaryOperator: public ASTNode {
public:
    enum class Type {
        kAddress,
        kMult,
        kPlus,
        kMinus,
        kLogicalNot,
        kNot,
    };

public:
    UnaryOperator(Type operatorType)
        : m_Type(operatorType) {}

    void Accept(Visitor& visitor) override {
        visitor.Visit(*this);
    }

private:
    Type m_Type;
};

}  // namespace ast
