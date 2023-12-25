#pragma once

#include <string>

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

    // void accept(Visitor *visitor) override;

private:
    Type m_Type;
};

}  // namespace ast
