#pragma once

#include <memory>

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>
#include <Clipl/Grammar/AST/Program/ExternalDeclaration.hpp>

namespace ast {

class TranslationUnit: public ASTNode {
public:
    TranslationUnit(std::shared_ptr<ExternalDeclaration> externalDeclaration)
        : m_ExternalDeclaration(externalDeclaration) {}

    TranslationUnit(std::shared_ptr<ExternalDeclaration> externalDeclaration,
                    std::shared_ptr<TranslationUnit> translationUnit)
        : m_ExternalDeclaration(externalDeclaration),
          m_TranslationUnitTail(translationUnit) {} 

    // void accept(Visitor *visitor) override;

private:
    std::shared_ptr<ExternalDeclaration> m_ExternalDeclaration = nullptr;
    std::shared_ptr<TranslationUnit> m_TranslationUnitTail = nullptr;
};

}  // namespace ast
