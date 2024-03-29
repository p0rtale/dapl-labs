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

    void Accept(Visitor& visitor) override {
        visitor.Visit(*this);
    }

    void AddSpecifier(RefT<Specifier> specifier) override {
        m_Specifiers.push_back(specifier);
    }

    std::vector<RefT<Specifier>> GetSpecifiers() const {
        return m_Specifiers;
    }

    RefT<IdentSpecifier> GetIdent() const {
        return m_Ident;
    }    

private:
    std::vector<RefT<Specifier>> m_Specifiers;
    RefT<IdentSpecifier> m_Ident;
};

}  // namespace ast
