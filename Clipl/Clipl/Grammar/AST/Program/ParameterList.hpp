#pragma once

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>


namespace ast {

class ParameterList: public ASTNode {
public:
    ParameterList();

    // void accept(Visitor *visitor) override;
};

}  // namespace ast
