#pragma once

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>
#include <Clipl/Grammar/AST/Expression/LogicalAndExpression.hpp>


namespace ast {

class LogicalOrExpression: public ASTNode {
public:
    LogicalOrExpression(std::shared_ptr<LogicalAndExpression> logicalAndExpression)
        : m_LogicalAndExpression(logicalAndExpression) {}

    LogicalOrExpression(std::shared_ptr<LogicalOrExpression> logicalOrExpression,
                        std::shared_ptr<LogicalAndExpression> logicalAndExpression)
        : m_LogicalOrExpression(logicalOrExpression),
          m_LogicalAndExpression(logicalAndExpression) {}

    // void accept(Visitor *visitor) override;

private:
    std::shared_ptr<LogicalOrExpression> m_LogicalOrExpression = nullptr;
    std::shared_ptr<LogicalAndExpression> m_LogicalAndExpression = nullptr;
};

}  // namespace ast
