#pragma once

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>


namespace ast {

class PrimaryExpression: public ASTNode {
public:
    PrimaryExpression();

    // void accept(Visitor *visitor) override;
};

}  // namespace ast
