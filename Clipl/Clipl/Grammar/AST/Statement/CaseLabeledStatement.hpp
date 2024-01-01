#pragma once

#include <memory>

#include <Clipl/Grammar/AST/Statement/LabeledStatement.hpp>
#include <Clipl/Grammar/AST/Statement/Statement.hpp>
#include <Clipl/Grammar/AST/Expression/ConstantExpression.hpp>


namespace ast {

class CaseLabeledStatement: public LabeledStatement {
public:
    CaseLabeledStatement(std::shared_ptr<ConstantExpression> constantExpression,
                         std::shared_ptr<Statement> statement)
        : m_Constexpr(constantExpression),
          m_Statement(statement) {}

    // void accept(Visitor *visitor) override;

private:
    std::shared_ptr<ConstantExpression> m_Constexpr;
    std::shared_ptr<Statement> m_Statement;
};

}  // namespace ast
