#pragma once

#include <string>
#include <memory>

#include <Clipl/Grammar/AST/Statement/LabeledStatement.hpp>
#include <Clipl/Grammar/AST/Statement/Statement.hpp>


namespace ast {

class IdentLabeledStatement: public LabeledStatement {
public:
    IdentLabeledStatement(std::string identifier,
                          std::shared_ptr<Statement> statement)
        : m_Identifier(std::move(identifier)),
          m_Statement(statement) {}

    // void accept(Visitor *visitor) override;

private:
    std::string m_Identifier;
    std::shared_ptr<Statement> m_Statement;
};

}  // namespace ast
