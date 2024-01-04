#pragma once

#include <unordered_map>
#include <memory>
#include <vector>
#include <optional>

#include <Clipl/Base.hpp>
#include <Clipl/SymbolTable/Symbol.hpp> 
#include <Clipl/Type/Type.hpp>


namespace clipl {

class Scope: public std::enable_shared_from_this<Scope> {
public:
    Scope() = default;

    void AddSymbol(Symbol symbol, RefT<type::Type> type) {
        if (HaveSymbol(symbol)) {
            // TODO: handle error
            CLIPL_ERROR("Scope AddSymbol: symbol already exists [symbol=\"{}\"]",
                        symbol.GetName());
        }
        m_SymbolTypes[symbol] = type;
        m_Symbols.push_back(symbol);
    }

    std::optional<RefT<type::Type>> GetTypeBySymbol(Symbol symbol) const {
        auto scope = shared_from_this();
        while (!scope->IsRootScope() && !scope->HaveSymbol(symbol)) {
            auto parentWRef = scope->GetParentScope();
            if (auto tmpParent = parentWRef.lock()) {
                scope = tmpParent;
            } else {
                // TODO: handle error
                CLIPL_ERROR("Scope GetTypeBySymbol: parent is expired [symbol=\"{}\"]",
                            symbol.GetName());                
            }
        }
        if (scope->HaveSymbol(symbol)) {
            return scope->m_SymbolTypes.at(symbol);
        }
        return std::nullopt;        
    }

    bool HaveSymbol(Symbol symbol) const {
        auto it = m_SymbolTypes.find(symbol);
        return (it != m_SymbolTypes.end());
    }

    void AddChild(RefT<Scope> child) {
        m_ChildrenScopes.push_back(child);
        child->m_ParentScope = weak_from_this();
    }

    RefT<Scope> GetChildScopeByIndex(size_t index) const {
        return m_ChildrenScopes.at(index);
    }

    WRefT<Scope> GetParentScope() const {
        return m_ParentScope;
    }

    bool IsRootScope() const {
        return m_ParentScope.expired();
    }

private:
    WRefT<Scope> m_ParentScope;
    std::vector<RefT<Scope>> m_ChildrenScopes;

    std::vector<Symbol> m_Symbols;
    std::unordered_map<Symbol, RefT<type::Type>> m_SymbolTypes;
};

}  // namespace clipl
