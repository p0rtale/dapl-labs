#pragma once

#include <Clipl/Grammar/AST/Statement/Statement.hpp>


namespace ast {

class IterationStatement: public Statement {
public:
    IterationStatement();

    // void accept(Visitor *visitor) override;
};

}  // namespace ast
