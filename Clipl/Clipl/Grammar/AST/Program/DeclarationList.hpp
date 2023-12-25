#pragma once

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>


namespace ast {

class DeclarationList: public ASTNode {
public:
    DeclarationList();

    // void accept(Visitor *visitor) override;
};

}  // namespace ast
