#pragma once

#include <Clipl/Grammar/AST/Program/Specifier/Specifier.hpp>


namespace ast {

class StorageClassSpecifier: public Specifier {
public:
    enum class Type {
        kTypedef,
        kExtern,
        kStatic,
    };

public:
    StorageClassSpecifier(Type type)
        : m_Type(type) {};

    void Accept(Visitor& visitor) override {
        visitor.Visit(*this);
    }

private:
    Type m_Type;
};

}  // namespace ast
