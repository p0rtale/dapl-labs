#pragma once

#include <Clipl/Grammar/AST/Statement/Statement.hpp>


namespace ast {

class ExpressionStatement: public Statement {
public:
    ExpressionStatement();

    // void accept(Visitor *visitor) override;
};

}  // namespace ast
