#pragma once

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>
#include <Clipl/Grammar/AST/Expression/ExclusiveOrExpression.hpp>


namespace ast {

class InclusiveOrExpression: public ASTNode {
public:
    InclusiveOrExpression(RefT<ExclusiveOrExpression> exclusiveOrExpression,
                          RefT<InclusiveOrExpression> inclusiveOrExpression = nullptr)
        : m_InclusiveOrExpression(inclusiveOrExpression),
          m_ExclusiveOrExpression(exclusiveOrExpression) {}

    void Accept(Visitor& visitor) override {
        visitor.Visit(*this);
    }

    RefT<InclusiveOrExpression> GetInclusiveOrExpression() const {
        return m_InclusiveOrExpression;
    }

    RefT<ExclusiveOrExpression> GetExclusiveOrExpression() const {
        return m_ExclusiveOrExpression;
    }

private:
    RefT<InclusiveOrExpression> m_InclusiveOrExpression;
    RefT<ExclusiveOrExpression> m_ExclusiveOrExpression;
};

}  // namespace ast
