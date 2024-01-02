#pragma once

#include <Clipl/Grammar/AST/Expression/PostfixExpression/PostfixExpression.hpp>
#include <Clipl/Grammar/AST/Expression/Expression.hpp>


namespace ast {

class IndexExpression: public PostfixExpression {
public:
    IndexExpression(RefT<PostfixExpression> postfixExpression,
                    RefT<Expression> indexExpr)
        : m_PostfixExpression(postfixExpression),
          m_IndexExpr(indexExpr) {}

    void Accept(Visitor& visitor) override {
        visitor.Visit(*this);
    }

    RefT<PostfixExpression> GetPostfixExpression() const {
        return m_PostfixExpression;
    }

    RefT<Expression> GetIndexExpr() const {
        return m_IndexExpr;
    }

private:
    RefT<PostfixExpression> m_PostfixExpression;
    RefT<Expression> m_IndexExpr;
};

}  // namespace ast
