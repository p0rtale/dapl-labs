#pragma once

#include <vector>

#include <Clipl/Grammar/AST/Statement/Statement.hpp>
#include <Clipl/Grammar/AST/Program/ExternalDeclaration/Declaration.hpp>


namespace ast {

class CompoundStatement: public Statement {
public:
    CompoundStatement() = default;

    CompoundStatement(std::vector<RefT<Statement>> statements)
        : m_Statements(std::move(statements)) {}

    CompoundStatement(std::vector<RefT<Declaration>> declarations)
        : m_Declarations(std::move(declarations)) {}

    CompoundStatement(std::vector<RefT<Declaration>> declarations,
                      std::vector<RefT<Statement>> statements)
        : m_Declarations(std::move(declarations)),
          m_Statements(std::move(statements)) {}

    void Accept(Visitor& visitor) override {
        visitor.Visit(*this);
    }

    std::vector<RefT<Declaration>> GetDeclarations() const {
        return m_Declarations;
    }

    std::vector<RefT<Statement>> GetStatements() const {
        return m_Statements;
    }

private:
    std::vector<RefT<Declaration>> m_Declarations;
    std::vector<RefT<Statement>> m_Statements;
};

}  // namespace ast
