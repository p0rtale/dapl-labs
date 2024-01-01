#pragma once

#include <Clipl/Grammar/AST/Program/KeywordSpecifier.hpp>


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

    // void accept(Visitor *visitor) override;

private:
    Type m_Type;
};

}  // namespace ast
