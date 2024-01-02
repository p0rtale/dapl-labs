#pragma once

#include <Clipl/Grammar/AST/Expression/AssignmentExpression/AssignmentExpression.hpp>
#include <Clipl/Grammar/AST/Expression/ConditionalExpression.hpp>


namespace ast {

class ConditionalAssignmentExpression: public AssignmentExpression {
public:
    ConditionalAssignmentExpression(RefT<ConditionalExpression> conditionalExpression)
        : m_ConditionalExpression(conditionalExpression) {}

    void Accept(Visitor& visitor) override {
        visitor.Visit(*this);
    }

private:
    RefT<ConditionalExpression> m_ConditionalExpression;
};

}  // namespace ast
