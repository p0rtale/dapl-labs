#pragma once

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>


namespace ast {

class UnaryExpression: public ASTNode {
public:
    UnaryExpression();

    // void accept(Visitor *visitor) override;
};

}  // namespace ast
