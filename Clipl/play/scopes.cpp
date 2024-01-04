#include <iostream>

#include <Clipl/Base.hpp>
#include <Clipl/Type/IntegerType.hpp>
#include <Clipl/SymbolTable/Scope.hpp>
#include <Clipl/Logger/Logger.hpp>

using namespace clipl;

int main() {
    Logger::init();

    auto integerType = CreateRef<type::IntegerType>();

    auto scopeRoot = CreateRef<Scope>();

    auto symbol1 = Symbol{"x"};
    auto symbol2 = Symbol{"y"};

    scopeRoot->AddSymbol(symbol1, integerType);
    if (!scopeRoot->HaveSymbol(symbol1)) {
        CLIPL_ERROR("scopeRoot HaveSymbol symbol1");
    }
    if (scopeRoot->HaveSymbol(symbol2)) {
        CLIPL_ERROR("scopeRoot HaveSymbol symbol2");
    }

    auto scopeChild1 = CreateRef<Scope>();
    auto scopeChild2 = CreateRef<Scope>();
    scopeRoot->AddChild(scopeChild1);
    scopeRoot->AddChild(scopeChild2);

    scopeChild1->AddSymbol(symbol2, integerType);

    auto type1 = scopeChild2->GetTypeBySymbol(symbol1);
    if (!type1) {
        CLIPL_ERROR("scopeChild2 GetTypeBySymbol symbol1");
    }

    auto type2 = scopeChild2->GetTypeBySymbol(symbol2);
    if (type2) {
        CLIPL_ERROR("scopeChild2 GetTypeBySymbol symbol2");
    }   

    return EXIT_SUCCESS;
}
