#pragma once

#include <Clipl/Grammar/AST/Program/ExternalDeclaration.hpp>
#include <Clipl/Grammar/AST/Program/DeclarationSpecifiers.hpp>
#include <Clipl/Grammar/AST/Program/Declarator.hpp>
#include <Clipl/Grammar/AST/Statement/CompoundStatement.hpp>


namespace ast {

class FunctionDefinition: public ExternalDeclaration {
public:
    FunctionDefinition(std::shared_ptr<DeclarationSpecifiers> declarationSpecifiers,
                       std::shared_ptr<Declarator> declarator,
                       std::shared_ptr<CompoundStatement> compoundStatement)
        : m_DeclarationSpecifiers(declarationSpecifiers),
          m_Declarator(declarator),
          m_CompoundStatement(compoundStatement) {}

    // void accept(Visitor *visitor) override;

private:
    std::shared_ptr<DeclarationSpecifiers> m_DeclarationSpecifiers = nullptr;
    std::shared_ptr<Declarator> m_Declarator = nullptr;
    std::shared_ptr<CompoundStatement> m_CompoundStatement = nullptr;
};

}  // namespace ast
