#pragma once

#include <memory>

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>
#include <Clipl/Grammar/AST/Expression/ExclusiveOrExpression.hpp>


namespace ast {

class InclusiveOrExpression: public ASTNode {
public:
    InclusiveOrExpression(std::shared_ptr<ExclusiveOrExpression> exclusiveOrExpression,
                          std::shared_ptr<InclusiveOrExpression> inclusiveOrExpression = nullptr)
        : m_InclusiveOrExpression(inclusiveOrExpression),
          m_ExclusiveOrExpression(exclusiveOrExpression) {}

    // void accept(Visitor *visitor) override;

private:
    std::shared_ptr<InclusiveOrExpression> m_InclusiveOrExpression;
    std::shared_ptr<ExclusiveOrExpression> m_ExclusiveOrExpression;
};

}  // namespace ast
