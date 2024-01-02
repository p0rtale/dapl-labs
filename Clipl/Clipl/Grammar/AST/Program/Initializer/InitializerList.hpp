#pragma once

#include <vector>

#include <Clipl/Grammar/AST/Program/Initializer/Initializer.hpp>


namespace ast {

class InitializerList: public Initializer {
public:
    InitializerList(std::vector<RefT<Initializer>> initializers)
        : m_Initializers(initializers) {}

    // void accept(Visitor *visitor) override;

private:
    std::vector<RefT<Initializer>> m_Initializers;
};

}  // namespace ast
