#pragma once

#include <memory>

#include <Clipl/Grammar/AST/Expression/AssignmentExpression.hpp>
#include <Clipl/Grammar/AST/Expression/ConditionalExpression.hpp>


namespace ast {

class ConditionalAssignmentExpression: public AssignmentExpression {
public:
    ConditionalAssignmentExpression(std::shared_ptr<ConditionalExpression> conditionalExpression)
        : m_ConditionalExpression(conditionalExpression) {}

    // void accept(Visitor *visitor) override;

private:
    std::shared_ptr<ConditionalExpression> m_ConditionalExpression;
};

}  // namespace ast
