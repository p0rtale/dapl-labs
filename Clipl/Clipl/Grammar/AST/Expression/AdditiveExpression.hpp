#pragma once

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>


namespace ast {

class AdditiveExpression: public ASTNode {
public:
    AdditiveExpression();

    // void accept(Visitor *visitor) override;
};

}  // namespace ast
