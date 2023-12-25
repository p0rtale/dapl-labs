#pragma once

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>


namespace ast {

class AbstractDeclarator: public ASTNode {
public:
    AbstractDeclarator();

    // void accept(Visitor *visitor) override;
};

}  // namespace ast
