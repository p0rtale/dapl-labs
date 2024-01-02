#pragma once

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>
#include <Clipl/Grammar/AST/Expression/InclusiveOrExpression.hpp>


namespace ast {

class LogicalAndExpression: public ASTNode {
public:
    LogicalAndExpression(RefT<InclusiveOrExpression> inclusiveOrExpression,
                         RefT<LogicalAndExpression> logicalAndExpression = nullptr)
        : m_LogicalAndExpression(logicalAndExpression),
          m_InclusiveOrExpression(inclusiveOrExpression) {}

    void Accept(Visitor& visitor) override {
        visitor.Visit(*this);
    }

    RefT<LogicalAndExpression> GetLogicalAndExpression() const {
        return m_LogicalAndExpression;
    }

    RefT<InclusiveOrExpression> GetInclusiveOrExpression() const {
        return m_InclusiveOrExpression;
    }

private:
    RefT<LogicalAndExpression> m_LogicalAndExpression;
    RefT<InclusiveOrExpression> m_InclusiveOrExpression;
};
}  // namespace ast
