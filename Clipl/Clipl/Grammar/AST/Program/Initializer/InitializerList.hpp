#pragma once

#include <vector>
#include <memory>

#include <Clipl/Grammar/AST/Program/Initializer/Initializer.hpp>


namespace ast {

class InitializerList: public Initializer {
public:
    InitializerList(std::vector<std::shared_ptr<Initializer>> initializers)
        : m_Initializers(initializers) {}

    // void accept(Visitor *visitor) override;

private:
    std::vector<std::shared_ptr<Initializer>> m_Initializers;
};

}  // namespace ast
