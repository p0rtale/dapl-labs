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

    std::string GetTypeStr() const {
        switch (m_Type) {
            case Type::kTypedef: return "typedef";
            case Type::kExtern:  return "extern";
            case Type::kStatic:  return "static";
            default: {
                CLIPL_ERROR("Invalid type in StorageClassSpecifier");
                return "";
            }
        }
    }

private:
    Type m_Type;
};

}  // namespace ast
