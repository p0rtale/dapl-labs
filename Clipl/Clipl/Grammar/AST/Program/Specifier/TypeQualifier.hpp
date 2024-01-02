#pragma once

#include <Clipl/Grammar/AST/Program/Specifier/Specifier.hpp>


namespace ast {

class TypeQualifier: public Specifier {
public:
    enum class Type {
        kConst,
        kVolatile,
    };

public:
    TypeQualifier(Type type)
        : m_Type(type) {};

    void Accept(Visitor& visitor) override {
        visitor.Visit(*this);
    }

private:
    Type m_Type;
};

}  // namespace ast
