#pragma once

#include <Clipl/Grammar/AST/Expression/AssignmentExpression/AssignmentExpression.hpp>
#include <Clipl/Grammar/AST/Expression/UnaryExpression/UnaryExpression.hpp>
#include <Clipl/Grammar/AST/Expression/AssignmentOperator.hpp>


namespace ast {

class UnaryAssignExpression: public AssignmentExpression {
public:
    UnaryAssignExpression(RefT<UnaryExpression> unaryExpression,
                          RefT<AssignmentOperator> assignmentOperator,
                          RefT<AssignmentExpression> assignmentExpression)
        : m_UnaryExpression(unaryExpression),
          m_AssignmentOperator(assignmentOperator),
          m_AssignmentExpression(assignmentExpression) {}

    // void accept(Visitor *visitor) override;

private:
    RefT<UnaryExpression> m_UnaryExpression;
    RefT<AssignmentOperator> m_AssignmentOperator;
    RefT<AssignmentExpression> m_AssignmentExpression;
};

}  // namespace ast
