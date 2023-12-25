#pragma once

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>


namespace ast {

class StructOrUnionSpecifier: public ASTNode {
public:
    StructOrUnionSpecifier();

    // void accept(Visitor *visitor) override;
};

}  // namespace ast
