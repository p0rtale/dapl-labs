#pragma once

#include <memory>

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>
#include <Clipl/Grammar/AST/Expression/AssignmentExpression/AssignmentExpression.hpp>


namespace ast {

class Expression: public ASTNode {
public:
    Expression(std::shared_ptr<AssignmentExpression> assignmentExpression,
               std::shared_ptr<Expression> expression = nullptr)
        : m_ExpressionHead(expression),
          m_AssignmentExpression(assignmentExpression) {}

    // void accept(Visitor *visitor) override;

private:
    std::shared_ptr<Expression> m_ExpressionHead;
    std::shared_ptr<AssignmentExpression> m_AssignmentExpression;
};

}  // namespace ast
