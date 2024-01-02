#pragma once

#include <Clipl/Grammar/AST/Expression/PostfixExpression/PostfixExpression.hpp>
#include <Clipl/Grammar/AST/Expression/Expression.hpp>


namespace ast {

class IndexExpression: public PostfixExpression {
public:
    IndexExpression(RefT<PostfixExpression> postfixExpression,
                    RefT<Expression> indexExpression)
        : m_PostfixExpression(postfixExpression),
          m_IndexExpression(indexExpression) {}

    // void accept(Visitor *visitor) override;

private:
    RefT<PostfixExpression> m_PostfixExpression;
    RefT<Expression> m_IndexExpression;
};

}  // namespace ast
