#pragma once

#include <vector>

#include <Clipl/Grammar/AST/Expression/PostfixExpression/PostfixExpression.hpp>
#include <Clipl/Grammar/AST/Expression/AssignmentExpression/AssignmentExpression.hpp>


namespace ast {

class CallExpression: public PostfixExpression {
public:
    CallExpression(RefT<PostfixExpression> postfixExpression,
                   std::vector<RefT<AssignmentExpression>> argumentExpressions = {})
        : m_PostfixExpression(postfixExpression),
          m_ArgumentExpressions(argumentExpressions) {}

    void Accept(Visitor& visitor) override {
        visitor.Visit(*this);
    }

private:
    RefT<PostfixExpression> m_PostfixExpression;
    std::vector<RefT<AssignmentExpression>> m_ArgumentExpressions;
};

}  // namespace ast
