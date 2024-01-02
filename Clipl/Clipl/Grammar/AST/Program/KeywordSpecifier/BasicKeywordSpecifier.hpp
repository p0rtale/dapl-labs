#pragma once

#include <Clipl/Grammar/AST/Program/KeywordSpecifier/KeywordSpecifier.hpp>


namespace ast {

class BasicKeywordSpecifier: public KeywordSpecifier {
public:
    enum class Type {
        kVoid,
        kChar,
        kShort,
        kInt,
        kLong,
        kFloat,
        kDouble,
        kSigned,
        kUnsigned,
    };

public:
    BasicKeywordSpecifier(Type type)
        : m_Type(type) {};

    void Accept(Visitor& visitor) override {
        visitor.Visit(*this);
    }

    std::string GetTypeStr() const {
        switch (m_Type) {
            case Type::kVoid:     return "void";
            case Type::kChar:     return "char";
            case Type::kShort:    return "short";
            case Type::kInt:      return "int";
            case Type::kLong:     return "long";
            case Type::kFloat:    return "float";
            case Type::kDouble:   return "double";
            case Type::kSigned:   return "signed";
            case Type::kUnsigned: return "unsigned";
            default: {
                CLIPL_ERROR("Invalid type in BasicKeywordSpecifier");
                return "";
            }
        }
    }

private:
    Type m_Type;
};

}  // namespace ast
