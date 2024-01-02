#pragma once

#include <vector>

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>
#include <Clipl/Grammar/AST/Program/KeywordSpecifier/KeywordSpecifier.hpp>
#include <Clipl/Grammar/AST/Program/IdentSpecifier.hpp>
#include <Clipl/Grammar/AST/Program/Specifier/TypeQualifier.hpp>


namespace ast {

class SpecifierQualifierList: public ASTNode {
public:
    SpecifierQualifierList(RefT<TypeQualifier> typeQualifier)
        : m_TypeQualifiers({typeQualifier}) {}

    SpecifierQualifierList(RefT<IdentSpecifier> identSpecifier)
        : m_IdentSpecifiers({identSpecifier}) {}

    SpecifierQualifierList(RefT<KeywordSpecifier> keywordSpecifier)
        : m_KeywordSpecifiers({keywordSpecifier}) {}

    // void accept(Visitor *visitor) override;

    void addTypeQualifier(RefT<TypeQualifier> typeQualifier) {
        m_TypeQualifiers.push_back(typeQualifier);
    }

    void addIdentSpecifier(RefT<IdentSpecifier> identSpecifier) {
        m_IdentSpecifiers.push_back(identSpecifier);
    }

    void addKeywordSpecifier(RefT<KeywordSpecifier> keywordSpecifier) {
        m_KeywordSpecifiers.push_back(keywordSpecifier);
    }

private:
    std::vector<RefT<TypeQualifier>> m_TypeQualifiers;
    std::vector<RefT<IdentSpecifier>> m_IdentSpecifiers;
    std::vector<RefT<KeywordSpecifier>> m_KeywordSpecifiers;
};

}  // namespace ast
