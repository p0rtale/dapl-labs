#pragma once

#include <Clipl/Grammar/AST/Base/ASTNode.hpp>


namespace ast {

class StorageClassSpecifier: public ASTNode {
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
