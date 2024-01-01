#pragma once

#include <memory>

#include <Clipl/Grammar/AST/Statement/LabeledStatement.hpp>
#include <Clipl/Grammar/AST/Statement/Statement.hpp>


namespace ast {

class DefaultLabeledStatement: public LabeledStatement {
public:
    DefaultLabeledStatement(std::shared_ptr<Statement> statement)
        : m_Statement(statement) {}

    // void accept(Visitor *visitor) override;

private:
    std::shared_ptr<Statement> m_Statement;
};

}  // namespace ast
