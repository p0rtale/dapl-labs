#pragma once

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>


namespace ast {

class Expression: public ASTNode {
public:
    Expression();

    // void accept(Visitor *visitor) override;
};

}  // namespace ast
