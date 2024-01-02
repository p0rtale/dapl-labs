#pragma once

#include <vector>
#include <memory>

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>
#include <Clipl/Grammar/AST/Program/KeywordSpecifier/KeywordSpecifier.hpp>
#include <Clipl/Grammar/AST/Program/IdentSpecifier.hpp>
#include <Clipl/Grammar/AST/Program/Specifier/TypeQualifier.hpp>


namespace ast {

class SpecifierQualifierList: public ASTNode {
public:
    SpecifierQualifierList(std::shared_ptr<TypeQualifier> typeQualifier)
        : m_TypeQualifiers({typeQualifier}) {}

    SpecifierQualifierList(std::shared_ptr<IdentSpecifier> identSpecifier)
        : m_IdentSpecifiers({identSpecifier}) {}

    SpecifierQualifierList(std::shared_ptr<KeywordSpecifier> keywordSpecifier)
        : m_KeywordSpecifiers({keywordSpecifier}) {}

    // void accept(Visitor *visitor) override;

    void addTypeQualifier(std::shared_ptr<TypeQualifier> typeQualifier) {
        m_TypeQualifiers.push_back(typeQualifier);
    }

    void addIdentSpecifier(std::shared_ptr<IdentSpecifier> identSpecifier) {
        m_IdentSpecifiers.push_back(identSpecifier);
    }

    void addKeywordSpecifier(std::shared_ptr<KeywordSpecifier> keywordSpecifier) {
        m_KeywordSpecifiers.push_back(keywordSpecifier);
    }

private:
    std::vector<std::shared_ptr<TypeQualifier>> m_TypeQualifiers;
    std::vector<std::shared_ptr<IdentSpecifier>> m_IdentSpecifiers;
    std::vector<std::shared_ptr<KeywordSpecifier>> m_KeywordSpecifiers;
};

}  // namespace ast
