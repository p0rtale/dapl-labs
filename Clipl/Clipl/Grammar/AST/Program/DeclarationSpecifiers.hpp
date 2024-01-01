#pragma once

#include <memory>

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>
#include <Clipl/Grammar/AST/Program/Specifier.hpp>

namespace ast {

class DeclarationSpecifiers: public ASTNode {
public:
    virtual ~DeclarationSpecifiers() = default;

    // void accept(Visitor *visitor) override;

    virtual void addSpecifier(std::shared_ptr<Specifier> specifier) = 0;
};

}  // namespace ast
