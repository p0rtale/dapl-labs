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

    // void accept(Visitor *visitor) override;

private:
    RefT<InclusiveOrExpression> m_InclusiveOrExpression;
    RefT<ExclusiveOrExpression> m_ExclusiveOrExpression;
};

}  // namespace ast
