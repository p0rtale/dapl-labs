#pragma once

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>


namespace ast {

class StructDeclarator: public ASTNode {
public:
    StructDeclarator();

    // void accept(Visitor *visitor) override;
};

}  // namespace ast
