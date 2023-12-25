#pragma once

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>


namespace ast {

class CastExpression: public ASTNode {
public:
    CastExpression();

    // void accept(Visitor *visitor) override;
};

}  // namespace ast
