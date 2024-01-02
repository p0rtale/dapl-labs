#pragma once

#include <Clipl/Grammar/AST/Statement/Statement.hpp>


namespace ast {

class SelectionStatement: public Statement {
public:
    virtual ~SelectionStatement() = default;

    // void accept(Visitor *visitor) override;
};

}  // namespace ast
