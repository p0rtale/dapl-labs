#pragma once

#include <vector>
#include <Clipl/Grammar/AST/Program/ExternalDeclaration/ExternalDeclaration.hpp>
#include <Clipl/Grammar/AST/Program/DeclarationSpecifiers/DeclarationSpecifiers.hpp>
#include <Clipl/Grammar/AST/Program/InitDeclarator.hpp>
#include <Clipl/Grammar/AST/Expression/AssignmentExpression/AssignmentExpression.hpp>


namespace ast {

class Declaration: public ExternalDeclaration {
public:
    Declaration(RefT<DeclarationSpecifiers> declarationSpecifiers)
        : m_DeclarationSpecifiers(declarationSpecifiers) {}

    Declaration(RefT<DeclarationSpecifiers> declarationSpecifiers,
                std::vector<RefT<InitDeclarator>> initDeclarators,
                RefT<AssignmentExpression> assignmentExpression = nullptr)
        : m_DeclarationSpecifiers(declarationSpecifiers),
          m_InitDeclarators(std::move(initDeclarators)),
          m_AssignmentExpression(assignmentExpression) {}

    void Accept(Visitor& visitor) override {
        visitor.Visit(*this);
    }

    RefT<DeclarationSpecifiers> GetDeclarationSpecifiers() const {
        return m_DeclarationSpecifiers;
    }

    std::vector<RefT<InitDeclarator>> GetInitDeclarators() const {
        return m_InitDeclarators;
    }

    RefT<AssignmentExpression> GetAssignmentExpression() const {
        return m_AssignmentExpression;
    }

private:
    RefT<DeclarationSpecifiers> m_DeclarationSpecifiers;
    std::vector<RefT<InitDeclarator>> m_InitDeclarators;
    RefT<AssignmentExpression> m_AssignmentExpression;
};

}  // namespace ast
