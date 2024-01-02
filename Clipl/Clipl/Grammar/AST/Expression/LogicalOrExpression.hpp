#pragma once

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>
#include <Clipl/Grammar/AST/Expression/LogicalAndExpression.hpp>


namespace ast {

class LogicalOrExpression: public ASTNode {
public:
    LogicalOrExpression(RefT<LogicalAndExpression> logicalAndExpression,
                        RefT<LogicalOrExpression> logicalOrExpression = nullptr)
        : m_LogicalOrExpression(logicalOrExpression),
          m_LogicalAndExpression(logicalAndExpression) {}

    void Accept(Visitor& visitor) override {
        visitor.Visit(*this);
    }

    RefT<LogicalOrExpression> GetLogicalOrExpression() const {
        return m_LogicalOrExpression;
    }

    RefT<LogicalAndExpression> GetLogicalAndExpression() const {
        return m_LogicalAndExpression;
    }

private:
    RefT<LogicalOrExpression> m_LogicalOrExpression;
    RefT<LogicalAndExpression> m_LogicalAndExpression;
};

}  // namespace ast
