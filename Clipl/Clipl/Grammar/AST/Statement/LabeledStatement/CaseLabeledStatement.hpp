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

    void Accept(Visitor& visitor) override {
        visitor.Visit(*this);
    }

    RefT<ConstantExpression> GetConstExpression() const {
        return m_Constexpr;
    }

    RefT<Statement> GetStatement() const {
        return m_Statement;
    }

private:
    RefT<ConstantExpression> m_Constexpr;
    RefT<Statement> m_Statement;
};

}  // namespace ast
