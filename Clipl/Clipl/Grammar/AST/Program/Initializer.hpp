#pragma once

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>


namespace ast {

class Initializer: public ASTNode {
public:
    Initializer();

    // void accept(Visitor *visitor) override;
};

}  // namespace ast
