#pragma once

#include <Clipl/Grammar/AST/Statement/Statement.hpp>


namespace ast {

class IterationStatement: public Statement {
public:
    virtual ~IterationStatement() = default;

    void Accept(Visitor& visitor) override {
        visitor.Visit(*this);
    }
};

}  // namespace ast
