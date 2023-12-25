#pragma once

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>


namespace ast {

class InitializerList: public ASTNode {
public:
    InitializerList();

    // void accept(Visitor *visitor) override;
};

}  // namespace ast
