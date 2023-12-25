#pragma once

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>


namespace ast {

class Declarator: public ASTNode {
public:
    Declarator();

    // void accept(Visitor *visitor) override;
};

}  // namespace ast
