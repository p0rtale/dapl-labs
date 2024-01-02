#pragma once

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>
#include <Clipl/Grammar/AST/Expression/AssignmentExpression/AssignmentExpression.hpp>


namespace ast {

class Expression: public ASTNode {
public:
    Expression(RefT<AssignmentExpression> assignmentExpression,
               RefT<Expression> expression = nullptr)
        : m_ExpressionHead(expression),
          m_AssignmentExpression(assignmentExpression) {}

    void Accept(Visitor& visitor) override {
        visitor.Visit(*this);
    }

private:
    RefT<Expression> m_ExpressionHead;
    RefT<AssignmentExpression> m_AssignmentExpression;
};

}  // namespace ast
