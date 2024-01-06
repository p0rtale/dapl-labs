#pragma once 

#include <vector>
#include <unordered_map>

#include <Clipl/Base.hpp>
#include <Clipl/SymbolTable/Symbol.hpp>
#include <Clipl/SymbolTable/Scope.hpp>
#include <Clipl/Type/Type.hpp>


namespace clipl {

class SymbolList {
public:
    using SymbolTypesT = std::vector<std::pair<Symbol, RefT<type::Type>>>;

public:
    SymbolList() = default;

    void AddSymbol(Symbol symbol, RefT<type::Type> type) {
        if (HaveSymbol(symbol)) {
            // TODO: handle error
            CLIPL_ERROR("SymbolList AddSymbol: symbol already exists [symbol=\"{}\"]",
                        symbol.GetName());
        }
        m_SymbolTypes[symbol] = type;
    }

    RefT<type::Type> GetSymbol(Symbol symbol) const {
        return m_SymbolTypes.at(symbol);
    }

    bool HaveSymbol(Symbol symbol) const {
        auto it = m_SymbolTypes.find(symbol);
        return (it != m_SymbolTypes.end());
    }

private:
    std::unordered_map<Symbol, RefT<type::Type>> m_SymbolTypes;
};

}  // namespace clipl
