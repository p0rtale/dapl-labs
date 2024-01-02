#pragma once

#include <Clipl/Grammar/AST/Program/DeclarationSpecifiers/DeclarationSpecifiers.hpp>
#include <Clipl/Grammar/AST/Program/Specifier/Specifier.hpp>
#include <Clipl/Grammar/AST/Program/KeywordSpecifier/KeywordSpecifier.hpp>


namespace ast {

class KeywordDeclarationSpecifiers: public DeclarationSpecifiers {
public:
    KeywordDeclarationSpecifiers(RefT<KeywordSpecifier> keywordSpecifier)
        : m_Keywords{keywordSpecifier} {}

    void Accept(Visitor& visitor) override {
        visitor.Visit(*this);
    }

    void AddSpecifier(RefT<Specifier> specifier) override {
        m_Specifiers.push_back(specifier);
    }

    void AddKeywordSpecifier(RefT<KeywordSpecifier> keyword) {
        m_Keywords.push_back(keyword);
    }

    std::vector<RefT<Specifier>> GetSpecifiers() const {
        return m_Specifiers;
    }

    std::vector<RefT<KeywordSpecifier>> GetKeywords() const {
        return m_Keywords;
    }

private:
    std::vector<RefT<Specifier>> m_Specifiers;
    std::vector<RefT<KeywordSpecifier>> m_Keywords;
};

}  // namespace ast
