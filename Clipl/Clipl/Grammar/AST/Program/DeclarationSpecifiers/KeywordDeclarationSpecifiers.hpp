#pragma once

#include <Clipl/Grammar/AST/Program/DeclarationSpecifiers/DeclarationSpecifiers.hpp>
#include <Clipl/Grammar/AST/Program/Specifier/Specifier.hpp>
#include <Clipl/Grammar/AST/Program/KeywordSpecifier/KeywordSpecifier.hpp>


namespace ast {

class KeywordDeclarationSpecifiers: public DeclarationSpecifiers {
public:
    KeywordDeclarationSpecifiers(RefT<KeywordSpecifier> keywordSpecifier)
        : m_Keywords{keywordSpecifier} {}

    // void accept(Visitor *visitor) override;

    void addSpecifier(RefT<Specifier> specifier) override {
        m_Specifiers.push_back(specifier);
    }

    void addKeywordSpecifier(RefT<KeywordSpecifier> keyword) {
        m_Keywords.push_back(keyword);
    }

private:
    std::vector<RefT<Specifier>> m_Specifiers;
    std::vector<RefT<KeywordSpecifier>> m_Keywords;
};

}  // namespace ast
