#pragma once

#include <Clipl/Grammar/AST/Program/ExternalDeclaration/ExternalDeclaration.hpp>
#include <Clipl/Grammar/AST/Program/DeclarationSpecifiers/DeclarationSpecifiers.hpp>
#include <Clipl/Grammar/AST/Program/Declarator/Declarator.hpp>
#include <Clipl/Grammar/AST/Statement/CompoundStatement.hpp>


namespace ast {

class FunctionDefinition: public ExternalDeclaration {
public:
    FunctionDefinition(RefT<DeclarationSpecifiers> declarationSpecifiers,
                       RefT<Declarator> declarator,
                       RefT<CompoundStatement> compoundStatement)
        : m_DeclarationSpecifiers(declarationSpecifiers),
          m_Declarator(declarator),
          m_CompoundStatement(compoundStatement) {}

    void Accept(Visitor& visitor) override {
        visitor.Visit(*this);
    }

    RefT<DeclarationSpecifiers> GetDeclarationSpecifiers() const {
        return m_DeclarationSpecifiers;
    }

    RefT<Declarator> GetDeclarator() const {
        return m_Declarator;
    }

    RefT<CompoundStatement> GetCompoundStatement() const {
        return m_CompoundStatement;
    }

private:
    RefT<DeclarationSpecifiers> m_DeclarationSpecifiers;
    RefT<Declarator> m_Declarator;
    RefT<CompoundStatement> m_CompoundStatement;
};

}  // namespace ast
