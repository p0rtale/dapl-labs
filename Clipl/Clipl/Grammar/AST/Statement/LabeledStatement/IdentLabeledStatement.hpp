#pragma once

#include <string>

#include <Clipl/Grammar/AST/Statement/LabeledStatement/LabeledStatement.hpp>
#include <Clipl/Grammar/AST/Statement/Statement.hpp>


namespace ast {

class IdentLabeledStatement: public LabeledStatement {
public:
    IdentLabeledStatement(std::string identifier,
                          RefT<Statement> statement)
        : m_Identifier(std::move(identifier)),
          m_Statement(statement) {}

    void Accept(Visitor& visitor) override {
        visitor.Visit(*this);
    }

    std::string GetIdentifier() const {
        return m_Identifier;
    }

    RefT<Statement> GetStatement() const {
        return m_Statement;
    }

private:
    std::string m_Identifier;
    RefT<Statement> m_Statement;
};

}  // namespace ast
