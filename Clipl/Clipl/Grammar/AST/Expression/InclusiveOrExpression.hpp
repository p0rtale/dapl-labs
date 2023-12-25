#pragma once

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>


namespace ast {

class InclusiveOrExpression: public ASTNode {
public:
    InclusiveOrExpression();

    // void accept(Visitor *visitor) override;
};

}  // namespace ast
