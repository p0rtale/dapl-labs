#pragma once

#include <Clipl/Grammar/AST/Statement/LabeledStatement/LabeledStatement.hpp>
#include <Clipl/Grammar/AST/Statement/Statement.hpp>
#include <Clipl/Grammar/AST/Expression/ConstantExpression.hpp>


namespace ast {

class CaseLabeledStatement: public LabeledStatement {
public:
    CaseLabeledStatement(RefT<ConstantExpression> constantExpression,
                         RefT<Statement> statement)
        : m_Constexpr(constantExpression),
          m_Statement(statement) {}

    // void accept(Visitor *visitor) override;

private:
    RefT<ConstantExpression> m_Constexpr;
    RefT<Statement> m_Statement;
};

}  // namespace ast
