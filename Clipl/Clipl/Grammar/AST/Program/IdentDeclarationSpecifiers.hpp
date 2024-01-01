#pragma once

#include <memory>

#include <Clipl/Grammar/AST/Program/DeclarationSpecifiers.hpp>
#include <Clipl/Grammar/AST/Program/Specifier.hpp>
#include <Clipl/Grammar/AST/Program/IdentSpecifier.hpp>


namespace ast {

class IdentDeclarationSpecifiers: public DeclarationSpecifiers {
public:
    IdentDeclarationSpecifiers(std::shared_ptr<IdentSpecifier> identSpecifier)
        : m_Ident(identSpecifier) {}

    IdentDeclarationSpecifiers(std::shared_ptr<IdentSpecifier> identSpecifier,
                               const std::vector<std::shared_ptr<Specifier>>& specifiers)
        : m_Specifiers(specifiers),
          m_Ident(identSpecifier) {}

    // void accept(Visitor *visitor) override;

    void addSpecifier(std::shared_ptr<Specifier> specifier) override {
        m_Specifiers.push_back(specifier);
    }

private:
    std::vector<std::shared_ptr<Specifier>> m_Specifiers;
    std::shared_ptr<IdentSpecifier> m_Ident;
};

}  // namespace ast
