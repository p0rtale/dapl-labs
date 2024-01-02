#pragma once

#include <Clipl/Grammar/AST/Expression/AssignmentExpression/AssignmentExpression.hpp>
#include <Clipl/Grammar/AST/Expression/ConditionalExpression.hpp>


namespace ast {

class ConditionalAssignmentExpression: public AssignmentExpression {
public:
    ConditionalAssignmentExpression(RefT<ConditionalExpression> conditionalExpression)
        : m_ConditionalExpression(conditionalExpression) {}

    // void accept(Visitor *visitor) override;

private:
    RefT<ConditionalExpression> m_ConditionalExpression;
};

}  // namespace ast
