#pragma once

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>


namespace ast {

class DirectDeclarator: public ASTNode {
public:
    DirectDeclarator();

    // void accept(Visitor *visitor) override;
};

}  // namespace ast