#pragma once

#include <Clipl/Grammar/AST/Program/Initializer/Initializer.hpp>
#include <Clipl/Grammar/AST/Expression/AssignmentExpression/AssignmentExpression.hpp>


namespace ast {

class ExpressionInitializer: public Initializer {
public:
    ExpressionInitializer(RefT<AssignmentExpression> assignmentExpression)
        : m_AssignmentExpression(assignmentExpression) {}

    void Accept(Visitor& visitor) override {
        visitor.Visit(*this);
    }

private:
    RefT<AssignmentExpression> m_AssignmentExpression;
};

}  // namespace ast
