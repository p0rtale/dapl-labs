#pragma once

#include <Clipl/Grammar/AST/Statement/LabeledStatement/LabeledStatement.hpp>
#include <Clipl/Grammar/AST/Statement/Statement.hpp>


namespace ast {

class DefaultLabeledStatement: public LabeledStatement {
public:
    DefaultLabeledStatement(RefT<Statement> statement)
        : m_Statement(statement) {}

    void Accept(Visitor& visitor) override {
        visitor.Visit(*this);
    }

    RefT<Statement> GetStatement() const {
        return m_Statement;
    }

private:
    RefT<Statement> m_Statement;
};

}  // namespace ast
