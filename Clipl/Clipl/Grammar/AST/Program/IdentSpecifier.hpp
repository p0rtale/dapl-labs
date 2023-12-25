#pragma once

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>


namespace ast {

class IdentSpecifier: public ASTNode {
public:
    IdentSpecifier();

    // void accept(Visitor *visitor) override;
};

}  // namespace ast
