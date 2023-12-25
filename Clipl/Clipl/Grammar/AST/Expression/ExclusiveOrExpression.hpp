#pragma once

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>


namespace ast {

class ExclusiveOrExpression: public ASTNode {
public:
    ExclusiveOrExpression();

    // void accept(Visitor *visitor) override;
};

}  // namespace ast
