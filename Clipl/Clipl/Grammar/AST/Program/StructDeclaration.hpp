#pragma once

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>


namespace ast {

class StructDeclaration: public ASTNode {
public:
    StructDeclaration();

    // void accept(Visitor *visitor) override;
};

}  // namespace ast
