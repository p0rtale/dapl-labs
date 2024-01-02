#pragma once

#include <memory>

#include <Clipl/Grammar/AST/Program/DeclarationSpecifiers/DeclarationSpecifiers.hpp>
#include <Clipl/Grammar/AST/Program/Specifier/Specifier.hpp>
#include <Clipl/Grammar/AST/Program/KeywordSpecifier/KeywordSpecifier.hpp>


namespace ast {

class KeywordDeclarationSpecifiers: public DeclarationSpecifiers {
public:
    KeywordDeclarationSpecifiers(std::shared_ptr<KeywordSpecifier> keywordSpecifier)
        : m_Keywords{keywordSpecifier} {}

    // void accept(Visitor *visitor) override;

    void addSpecifier(std::shared_ptr<Specifier> specifier) override {
        m_Specifiers.push_back(specifier);
    }

    void addKeywordSpecifier(std::shared_ptr<KeywordSpecifier> keyword) {
        m_Keywords.push_back(keyword);
    }

private:
    std::vector<std::shared_ptr<Specifier>> m_Specifiers;
    std::vector<std::shared_ptr<KeywordSpecifier>> m_Keywords;
};

}  // namespace ast
