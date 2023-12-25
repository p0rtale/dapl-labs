#pragma once

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>


namespace ast {

class StatementList: public ASTNode {
public:
    StatementList();

    // void accept(Visitor *visitor) override;
};

}  // namespace ast
