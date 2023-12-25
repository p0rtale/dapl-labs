#pragma once

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>


namespace ast {

class SpecifierQualifierList: public ASTNode {
public:
    SpecifierQualifierList();

    // void accept(Visitor *visitor) override;
};

}  // namespace ast
