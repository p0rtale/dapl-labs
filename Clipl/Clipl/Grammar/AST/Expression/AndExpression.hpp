#pragma once

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>
#include <Clipl/Grammar/AST/Expression/EqualityExpression.hpp>


namespace ast {

class AndExpression: public ASTNode {
public:
    AndExpression(RefT<EqualityExpression> equalityExpression,
                  RefT<AndExpression> andExpression = nullptr)
        : m_AndExpression(andExpression),
          m_EqualityExpression(equalityExpression) {}

    void Accept(Visitor& visitor) override {
        visitor.Visit(*this);
    }

    RefT<AndExpression> GetAndExpression() const {
        return m_AndExpression;
    }

    RefT<EqualityExpression> GetEqualityExpression() const {
        return m_EqualityExpression;
    }

private:
    RefT<AndExpression> m_AndExpression;
    RefT<EqualityExpression> m_EqualityExpression;
};

}  // namespace ast
