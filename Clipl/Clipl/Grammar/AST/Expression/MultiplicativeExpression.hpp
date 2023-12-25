#pragma once

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>


namespace ast {

class MultiplicativeExpression: public ASTNode {
public:
    MultiplicativeExpression();

    // void accept(Visitor *visitor) override;
};

}  // namespace ast
