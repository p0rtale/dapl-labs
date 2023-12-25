#pragma once

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>
#include <Clipl/Grammar/AST/Expression/InclusiveOrExpression.hpp>


namespace ast {

class LogicalAndExpression: public ASTNode {
public:
    LogicalAndExpression(std::shared_ptr<InclusiveOrExpression> inclusiveOrExpression)
        : m_InclusiveOrExpression(inclusiveOrExpression) {}

    LogicalAndExpression(std::shared_ptr<LogicalAndExpression> logicalAndExpression,
                        std::shared_ptr<InclusiveOrExpression> inclusiveOrExpression)
        : m_LogicalAndExpression(logicalAndExpression),
          m_InclusiveOrExpression(inclusiveOrExpression) {}

    // void accept(Visitor *visitor) override;

private:
    std::shared_ptr<LogicalAndExpression> m_LogicalAndExpression = nullptr;
    std::shared_ptr<InclusiveOrExpression> m_InclusiveOrExpression = nullptr;
};
}  // namespace ast
