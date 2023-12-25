#pragma once

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>


namespace ast {

class PostfixExpression: public ASTNode {
public:
    PostfixExpression();

    // void accept(Visitor *visitor) override;
};

}  // namespace ast
