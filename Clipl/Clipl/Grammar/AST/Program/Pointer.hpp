#pragma once

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>


namespace ast {

class Pointer: public ASTNode {
public:
    Pointer();

    // void accept(Visitor *visitor) override;
};

}  // namespace ast
