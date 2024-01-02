#pragma once

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>
#include <Clipl/Grammar/AST/Program/ExternalDeclaration/ExternalDeclaration.hpp>

namespace ast {

class TranslationUnit: public ASTNode {
public:
    TranslationUnit(RefT<ExternalDeclaration> externalDeclaration)
        : m_ExternalDeclaration(externalDeclaration) {}

    TranslationUnit(RefT<ExternalDeclaration> externalDeclaration,
                    RefT<TranslationUnit> translationUnit)
        : m_ExternalDeclaration(externalDeclaration),
          m_TranslationUnitTail(translationUnit) {} 

    void Accept(Visitor& visitor) override {
        visitor.Visit(*this);
    }

private:
    RefT<ExternalDeclaration> m_ExternalDeclaration;
    RefT<TranslationUnit> m_TranslationUnitTail;
};

}  // namespace ast
