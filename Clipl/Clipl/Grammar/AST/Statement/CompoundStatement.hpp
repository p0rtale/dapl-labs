#pragma once

#include <vector>
#include <memory>

#include <Clipl/Grammar/AST/Statement/Statement.hpp>
#include <Clipl/Grammar/AST/Program/ExternalDeclaration/Declaration.hpp>


namespace ast {

class CompoundStatement: public Statement {
public:
    CompoundStatement() = default;

    CompoundStatement(std::vector<std::shared_ptr<Statement>> statements)
        : m_Statements(std::move(statements)) {}

    CompoundStatement(std::vector<std::shared_ptr<Declaration>> declarations)
        : m_Declarations(std::move(declarations)) {}

    CompoundStatement(std::vector<std::shared_ptr<Declaration>> declarations,
                      std::vector<std::shared_ptr<Statement>> statements)
        : m_Declarations(std::move(declarations)),
          m_Statements(std::move(statements)) {}

    // void accept(Visitor *visitor) override;

private:
    std::vector<std::shared_ptr<Declaration>> m_Declarations;
    std::vector<std::shared_ptr<Statement>> m_Statements;
};

}  // namespace ast
