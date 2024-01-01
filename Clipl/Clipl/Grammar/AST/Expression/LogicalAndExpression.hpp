#pragma once

#include <memory>

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>
#include <Clipl/Grammar/AST/Expression/InclusiveOrExpression.hpp>


namespace ast {

class LogicalAndExpression: public ASTNode {
public:
    LogicalAndExpression(std::shared_ptr<InclusiveOrExpression> inclusiveOrExpression,
                         std::shared_ptr<LogicalAndExpression> logicalAndExpression = nullptr)
        : m_LogicalAndExpression(logicalAndExpression),
          m_InclusiveOrExpression(inclusiveOrExpression) {}

    // void accept(Visitor *visitor) override;

private:
    std::shared_ptr<LogicalAndExpression> m_LogicalAndExpression;
    std::shared_ptr<InclusiveOrExpression> m_InclusiveOrExpression;
};
}  // namespace ast
