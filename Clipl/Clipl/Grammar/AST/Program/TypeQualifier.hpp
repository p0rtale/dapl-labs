#pragma once

#include <Clipl/Grammar/AST/Program/Specifier.hpp>


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

    // void accept(Visitor *visitor) override;

private:
    Type m_Type;
};

}  // namespace ast
