#pragma once

#include <vector>
#include <memory>

#include <Clipl/Grammar/AST/Expression/PostfixExpression.hpp>
#include <Clipl/Grammar/AST/Expression/AssignmentExpression.hpp>


namespace ast {

class CallExpression: public PostfixExpression {
public:
    CallExpression(std::shared_ptr<PostfixExpression> postfixExpression,
                   std::vector<std::shared_ptr<AssignmentExpression>> argumentExpressions = {})
        : m_PostfixExpression(postfixExpression),
          m_ArgumentExpressions(argumentExpressions) {}

    // void accept(Visitor *visitor) override;

private:
    std::shared_ptr<PostfixExpression> m_PostfixExpression;
    std::vector<std::shared_ptr<AssignmentExpression>> m_ArgumentExpressions;
};

}  // namespace ast
