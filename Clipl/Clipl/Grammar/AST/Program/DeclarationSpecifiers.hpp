#pragma once

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>


namespace ast {

class DeclarationSpecifiers: public ASTNode {
public:
    DeclarationSpecifiers();

    // void accept(Visitor *visitor) override;
};

}  // namespace ast
