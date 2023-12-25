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

    // void accept(Visitor *visitor) override;

private:
    Type m_Type;
};

}  // namespace ast
