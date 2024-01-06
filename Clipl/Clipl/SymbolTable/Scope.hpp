#pragma once

#include <unordered_map>
#include <memory>
#include <vector>
#include <optional>

#include <Clipl/Base.hpp>
#include <Clipl/SymbolTable/Symbol.hpp> 
#include <Clipl/Type/Type.hpp>
#include <Clipl/SymbolTable/SymbolList.hpp>


namespace clipl {

class Scope: public std::enable_shared_from_this<Scope> {
public:
    using SymbolTypesT = std::vector<std::pair<Symbol, RefT<type::Type>>>;

public:
    Scope() = default; 

    Scope(Symbol label): m_Label(label) {}

    Symbol GetLabel() const {
        return m_Label;
    }

    void AddSymbol(Symbol symbol, RefT<type::Type> type, bool isDefined = false) {
        m_Symbols.AddSymbol(symbol, type);
        m_AllSymbolsInOrder.push_back({symbol, type});
        if (isDefined) {
            type->SetDefine();
        }
    }

    void AddTagSymbol(Symbol symbol, RefT<type::Type> type, bool isDefined = false) {
        m_TagSymbols.AddSymbol(symbol, type);
        m_AllSymbolsInOrder.push_back({symbol, type});
        if (isDefined) {
            type->SetDefine();
        }
    }

    std::optional<RefT<type::Type>> FindSymbol(Symbol symbol) const {
        auto scope = findScopeBySymbol(symbol, false);
        if (scope->HaveSymbol(symbol)) {
            return scope->m_Symbols.GetSymbol(symbol);
        }
        return std::nullopt;
    }

    std::optional<RefT<type::Type>> FindTagSymbol(Symbol symbol) const {
        auto scope = findScopeBySymbol(symbol, true);
        if (scope->HaveTagSymbol(symbol)) {
            return scope->m_TagSymbols.GetSymbol(symbol);
        }
        return std::nullopt;    
    }

    bool HaveSymbol(Symbol symbol) const {
        return m_Symbols.HaveSymbol(std::move(symbol));
    }

    bool HaveTagSymbol(Symbol symbol) const {
        return m_TagSymbols.HaveSymbol(std::move(symbol));
    }

    RefT<type::Type> GetSymbol(Symbol symbol) const {
        return m_Symbols.GetSymbol(std::move(symbol));
    }

    RefT<type::Type> GetTagSymbol(Symbol symbol) const {
        return m_TagSymbols.GetSymbol(std::move(symbol));
    }

    SymbolTypesT GetSymbolTypes() const {
        return m_AllSymbolsInOrder;
    }

    void AddChild(RefT<Scope> child) {
        m_ChildrenScopes.push_back(child);
        child->m_ParentScope = weak_from_this();
    }

    std::vector<RefT<Scope>> GetChildrenScopes() const {
        return m_ChildrenScopes;
    }

    RefT<Scope> GetChildScopeByIndex(size_t index) const {
        return m_ChildrenScopes.at(index);
    }

    WRefT<Scope> GetParentScope() const {
        return m_ParentScope;
    }

    bool IsGlobalScope() const {
        return m_ParentScope.expired();
    }

private:
    bool haveSymbol(Symbol symbol, bool tag) const {
        if (!tag) {
            return HaveSymbol(std::move(symbol));
        }
        return HaveTagSymbol(std::move(symbol));
    }   

    RefT<const Scope> findScopeBySymbol(Symbol symbol, bool tag) const {
        auto scope = shared_from_this();
        while (!scope->IsGlobalScope() && !scope->haveSymbol(symbol, tag)) {
            auto parentWRef = scope->GetParentScope();
            if (auto tmpParent = parentWRef.lock()) {
                scope = tmpParent;
            } else {
                // TODO: handle error
                CLIPL_ERROR("Scope findScopeBySymbol: parent is expired [symbol=\"{}\"]",
                            symbol.GetName());                
            }
        }
        return scope;
    }

private:
    Symbol m_Label;

    WRefT<Scope> m_ParentScope;
    std::vector<RefT<Scope>> m_ChildrenScopes;

    SymbolTypesT m_AllSymbolsInOrder;

    SymbolList m_TagSymbols;
    SymbolList m_Symbols;
};

}  // namespace clipl
