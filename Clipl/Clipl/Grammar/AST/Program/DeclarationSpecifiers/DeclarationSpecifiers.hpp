#pragma once

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>
#include <Clipl/Grammar/AST/Program/Specifier/Specifier.hpp>

namespace ast {

class DeclarationSpecifiers: public ASTNode {
public:
    virtual ~DeclarationSpecifiers() = default;

    // void accept(Visitor *visitor) override;

    virtual void addSpecifier(RefT<Specifier> specifier) = 0;
};

}  // namespace ast
