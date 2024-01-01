#pragma once

#include <memory>

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>
#include <Clipl/Grammar/AST/Expression/AndExpression.hpp>


namespace ast {

class ExclusiveOrExpression: public ASTNode {
public:
    ExclusiveOrExpression(std::shared_ptr<AndExpression> andExpression,
                          std::shared_ptr<ExclusiveOrExpression> exclusiveOrExpression = nullptr)
        : m_ExclusiveOrExpression(exclusiveOrExpression),
          m_AndExpression(andExpression) {}

    // void accept(Visitor *visitor) override;

private:
    std::shared_ptr<ExclusiveOrExpression> m_ExclusiveOrExpression;
    std::shared_ptr<AndExpression> m_AndExpression;
};

}  // namespace ast
