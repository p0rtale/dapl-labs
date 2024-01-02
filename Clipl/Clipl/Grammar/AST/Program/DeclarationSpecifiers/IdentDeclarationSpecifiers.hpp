#pragma once

#include <Clipl/Grammar/AST/Program/DeclarationSpecifiers/DeclarationSpecifiers.hpp>
#include <Clipl/Grammar/AST/Program/Specifier/Specifier.hpp>
#include <Clipl/Grammar/AST/Program/IdentSpecifier.hpp>


namespace ast {

class IdentDeclarationSpecifiers: public DeclarationSpecifiers {
public:
    IdentDeclarationSpecifiers(RefT<IdentSpecifier> identSpecifier)
        : m_Ident(identSpecifier) {}

    IdentDeclarationSpecifiers(RefT<IdentSpecifier> identSpecifier,
                               const std::vector<RefT<Specifier>>& specifiers)
        : m_Specifiers(specifiers),
          m_Ident(identSpecifier) {}

    // void accept(Visitor *visitor) override;

    void addSpecifier(RefT<Specifier> specifier) override {
        m_Specifiers.push_back(specifier);
    }

private:
    std::vector<RefT<Specifier>> m_Specifiers;
    RefT<IdentSpecifier> m_Ident;
};

}  // namespace ast
