#pragma once

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>


namespace ast {

class EnumSpecifier: public ASTNode {
public:
    EnumSpecifier();

    // void accept(Visitor *visitor) override;
};

}  // namespace ast
