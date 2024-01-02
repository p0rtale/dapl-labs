#pragma once

#include <string>
#include <vector>

#include <Clipl/Grammar/AST/Program/KeywordSpecifier/KeywordSpecifier.hpp>
#include <Clipl/Grammar/AST/Program/Enumerator.hpp>


namespace ast {

class EnumSpecifier: public KeywordSpecifier {
public:
    EnumSpecifier(std::string identifier,
                  std::vector<RefT<Enumerator>> enumeratorList = {})
        : m_Identifier(std::move(identifier)),
          m_EnumeratorList(enumeratorList) {}

    // void accept(Visitor *visitor) override;

private:
    std::string m_Identifier;
    std::vector<RefT<Enumerator>> m_EnumeratorList;
};

}  // namespace ast
