#pragma once

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>


namespace ast {

class Initializer: public ASTNode {
public:
    virtual ~Initializer() = default;

    // void accept(Visitor *visitor) override;
};

}  // namespace ast
