#pragma once

#include <memory>

#include <Clipl/Grammar/AST/Expression/PostfixExpression/PostfixExpression.hpp>
#include <Clipl/Grammar/AST/Expression/Expression.hpp>


namespace ast {

class IndexExpression: public PostfixExpression {
public:
    IndexExpression(std::shared_ptr<PostfixExpression> postfixExpression,
                    std::shared_ptr<Expression> indexExpression)
        : m_PostfixExpression(postfixExpression),
          m_IndexExpression(indexExpression) {}

    // void accept(Visitor *visitor) override;

private:
    std::shared_ptr<PostfixExpression> m_PostfixExpression;
    std::shared_ptr<Expression> m_IndexExpression;
};

}  // namespace ast
