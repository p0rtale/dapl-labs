#pragma once

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>
#include <Clipl/Grammar/AST/Expression/AndExpression.hpp>


namespace ast {

class ExclusiveOrExpression: public ASTNode {
public:
    ExclusiveOrExpression(RefT<AndExpression> andExpression,
                          RefT<ExclusiveOrExpression> exclusiveOrExpression = nullptr)
        : m_ExclusiveOrExpression(exclusiveOrExpression),
          m_AndExpression(andExpression) {}

    void Accept(Visitor& visitor) override {
        visitor.Visit(*this);
    }

private:
    RefT<ExclusiveOrExpression> m_ExclusiveOrExpression;
    RefT<AndExpression> m_AndExpression;
};

}  // namespace ast
