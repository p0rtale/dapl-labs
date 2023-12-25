#pragma once

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>


namespace ast {

class InitDeclarator: public ASTNode {
public:
    InitDeclarator();

    // void accept(Visitor *visitor) override;
};

}  // namespace ast
