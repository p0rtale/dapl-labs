#pragma once

#include <Clipl/Grammar/AST/Program/Specifier.hpp>


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

    // void accept(Visitor *visitor) override;

private:
    Type m_Type;
};

}  // namespace ast
