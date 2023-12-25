#pragma once

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>


namespace ast {

class InitDeclaratorList: public ASTNode {
public:
    InitDeclaratorList();

    // void accept(Visitor *visitor) override;
};

}  // namespace ast
