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

    std::string GetTypeStr() const {
        switch (m_Type) {
            case Type::kConst:    return "const";
            case Type::kVolatile: return "volatile";
            default: {
                CLIPL_ERROR("Invalid type in TypeQualifier");
                return "";
            }
        }
    }

private:
    Type m_Type;
};

}  // namespace ast
