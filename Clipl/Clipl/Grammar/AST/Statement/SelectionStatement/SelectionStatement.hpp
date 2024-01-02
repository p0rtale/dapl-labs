#pragma once

#include <Clipl/Grammar/AST/Statement/Statement.hpp>


namespace ast {

class SelectionStatement: public Statement {
public:
    virtual ~SelectionStatement() = default;

    void Accept(Visitor& visitor) override {
        visitor.Visit(*this);
    }
};

}  // namespace ast
