#pragma once

#include <unordered_map>
#include <fstream>
#include <ranges>

#include <Clipl/SymbolTable/Symbol.hpp>
#include <Clipl/SymbolTable/Scope.hpp>


namespace clipl {

class SymbolTree {
public:
    SymbolTree()
        : m_GlobalScope(CreateRef<Scope>(Symbol{"GlobalScope"})) {}

    RefT<Scope> GetGlobalScope() const {
        return m_GlobalScope;
    }

private:
    RefT<Scope> m_GlobalScope;
};

}  // namespace clipl
