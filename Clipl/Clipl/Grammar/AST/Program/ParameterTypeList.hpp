#pragma once

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>


namespace ast {

class ParameterTypeList: public ASTNode {
public:
    ParameterTypeList();

    // void accept(Visitor *visitor) override;
};

}  // namespace ast
