#pragma once

#include <memory>

#include <Clipl/Grammar/AST/Expression/AssignmentExpression/AssignmentExpression.hpp>
#include <Clipl/Grammar/AST/Expression/UnaryExpression/UnaryExpression.hpp>
#include <Clipl/Grammar/AST/Expression/AssignmentOperator.hpp>


namespace ast {

class UnaryAssignExpression: public AssignmentExpression {
public:
    UnaryAssignExpression(std::shared_ptr<UnaryExpression> unaryExpression,
                          std::shared_ptr<AssignmentOperator> assignmentOperator,
                          std::shared_ptr<AssignmentExpression> assignmentExpression)
        : m_UnaryExpression(unaryExpression),
          m_AssignmentOperator(assignmentOperator),
          m_AssignmentExpression(assignmentExpression) {}

    // void accept(Visitor *visitor) override;

private:
    std::shared_ptr<UnaryExpression> m_UnaryExpression;
    std::shared_ptr<AssignmentOperator> m_AssignmentOperator;
    std::shared_ptr<AssignmentExpression> m_AssignmentExpression;
};

}  // namespace ast
