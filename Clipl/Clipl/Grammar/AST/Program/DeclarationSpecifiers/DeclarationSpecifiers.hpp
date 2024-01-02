#pragma once

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>
#include <Clipl/Grammar/AST/Program/Specifier/Specifier.hpp>

namespace ast {

class DeclarationSpecifiers: public ASTNode {
public:
    virtual ~DeclarationSpecifiers() = default;

    void Accept(Visitor& visitor) override {
        visitor.Visit(*this);
    }

    virtual void AddSpecifier(RefT<Specifier> specifier) = 0;
};

}  // namespace ast
