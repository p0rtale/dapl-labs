#pragma once

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>


namespace ast {

class ParameterDeclaration: public ASTNode {
public:
    ParameterDeclaration();

    // void accept(Visitor *visitor) override;
};

}  // namespace ast
