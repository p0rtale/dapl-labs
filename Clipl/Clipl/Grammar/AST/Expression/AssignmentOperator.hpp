#pragma once

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>


namespace ast {

class AssignmentOperator: public ASTNode {
public:
    enum class Type {
        kAssign,
        kMulAssign,
        kDivAssign,
        kModAssign,
        kPlusAssign,
        kMinusAssign,
        kShiftLeftAssign,
        kShiftRightAssign,
        kLogicalAndAssign,
        kLogicalOrAssign,
        kXorAssign,
    };

public:
    AssignmentOperator(Type operatorType)
        : m_Type(operatorType) {}

    void Accept(Visitor& visitor) override {
        visitor.Visit(*this);
    }

private:
    Type m_Type;
};

}  // namespace ast
