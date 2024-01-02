#pragma once

#include <string>
#include <vector>

#include <Clipl/Grammar/AST/Program/KeywordSpecifier/KeywordSpecifier.hpp>
#include <Clipl/Grammar/AST/Program/StructDeclaration.hpp>


namespace ast {

enum class StructOrUnionType {
    kStruct,
    kUnion,
};

class StructOrUnionSpecifier: public KeywordSpecifier {
public:
    StructOrUnionSpecifier(StructOrUnionType type, std::string identifier,
                           std::vector<RefT<StructDeclaration>> structDeclarationList = {})
        : m_Type(type),
          m_Identifier(std::move(identifier)),
          m_StructDeclarationList(structDeclarationList) {}
    
    void Accept(Visitor& visitor) override {
        visitor.Visit(*this);
    }

    std::string GetTypeStr() const {
        switch (m_Type) {
            case StructOrUnionType::kStruct: return "struct";
            case StructOrUnionType::kUnion:  return "union";
            default: {
                CLIPL_ERROR("Invalid type in StructOrUnionSpecifier");
                return "";
            }
        }
    }

    std::string GetIdentifier() const {
        return m_Identifier;
    }

    std::vector<RefT<StructDeclaration>> GetStructDeclarationList() const {
        return m_StructDeclarationList;
    }

private:
    StructOrUnionType m_Type;

    std::string m_Identifier;
    std::vector<RefT<StructDeclaration>> m_StructDeclarationList;
};

}  // namespace ast
