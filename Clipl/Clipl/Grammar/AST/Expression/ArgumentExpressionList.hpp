#pragma once

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>


namespace ast {

class ArgumentExpressionList: public ASTNode {
public:
    ArgumentExpressionList();

    // void accept(Visitor *visitor) override;
};

}  // namespace ast
