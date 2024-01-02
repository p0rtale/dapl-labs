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

private:
    std::string m_Identifier;
    RefT<Statement> m_Statement;
};

}  // namespace ast
