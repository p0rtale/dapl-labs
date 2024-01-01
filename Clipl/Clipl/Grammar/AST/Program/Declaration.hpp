#pragma once

#include <vector>
#include <memory>

#include <Clipl/Grammar/AST/Program/ExternalDeclaration.hpp>
#include <Clipl/Grammar/AST/Program/DeclarationSpecifiers.hpp>
#include <Clipl/Grammar/AST/Program/InitDeclarator.hpp>
#include <Clipl/Grammar/AST/Expression/AssignmentExpression.hpp>


namespace ast {

class Declaration: public ExternalDeclaration {
public:
    Declaration(std::shared_ptr<DeclarationSpecifiers> declarationSpecifiers)
        : m_DeclarationSpecifiers(declarationSpecifiers) {}

    Declaration(std::shared_ptr<DeclarationSpecifiers> declarationSpecifiers,
                std::vector<std::shared_ptr<InitDeclarator>> initDeclarators,
                std::shared_ptr<AssignmentExpression> assignmentExpression = nullptr)
        : m_DeclarationSpecifiers(declarationSpecifiers),
          m_InitDeclarators(std::move(initDeclarators)),
          m_AssignmentExpression(assignmentExpression) {}

    // void accept(Visitor *visitor) override;

private:
    std::shared_ptr<DeclarationSpecifiers> m_DeclarationSpecifiers;
    std::vector<std::shared_ptr<InitDeclarator>> m_InitDeclarators;
    std::shared_ptr<AssignmentExpression> m_AssignmentExpression;
};

}  // namespace ast
