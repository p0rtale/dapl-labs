#pragma once

#include <memory>

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>
#include <Clipl/Grammar/AST/Expression/EqualityExpression.hpp>


namespace ast {

class AndExpression: public ASTNode {
public:
    AndExpression(std::shared_ptr<EqualityExpression> equalityExpression,
                  std::shared_ptr<AndExpression> andExpression = nullptr)
        : m_AndExpression(andExpression),
          m_EqualityExpression(equalityExpression) {}

    // void accept(Visitor *visitor) override;

private:
    std::shared_ptr<AndExpression> m_AndExpression;
    std::shared_ptr<EqualityExpression> m_EqualityExpression;
};

}  // namespace ast
