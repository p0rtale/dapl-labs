#pragma once

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>


namespace ast {

class SpecifierList: public ASTNode {
public:
    SpecifierList();

    // void accept(Visitor *visitor) override;
};

}  // namespace ast
