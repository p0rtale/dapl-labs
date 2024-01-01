#pragma once

#include <memory>

#include <Clipl/Grammar/AST/Program/Initializer.hpp>
#include <Clipl/Grammar/AST/Expression/AssignmentExpression.hpp>


namespace ast {

class ExpressionInitializer: public Initializer {
public:
    ExpressionInitializer(std::shared_ptr<AssignmentExpression> assignmentExpression)
        : m_AssignmentExpression(assignmentExpression) {}

    // void accept(Visitor *visitor) override;

private:
    std::shared_ptr<AssignmentExpression> m_AssignmentExpression;
};

}  // namespace ast
