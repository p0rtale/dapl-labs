#pragma once

#include <memory>

#include <Clipl/Grammar/AST/Program/DirectDeclarator.hpp>
#include <Clipl/Grammar/AST/Program/ParameterTypeList.hpp>


namespace ast {

class ParameterDirectDeclarator: public DirectDeclarator {
public:
    ParameterDirectDeclarator(std::shared_ptr<DirectDeclarator> directDeclarator,
                              std::shared_ptr<ParameterTypeList> parameterTypeList = nullptr)
        : m_DirectDeclarator(directDeclarator),
          m_ParameterTypeList(parameterTypeList) {}

    // void accept(Visitor *visitor) override;

private:
    std::shared_ptr<DirectDeclarator> m_DirectDeclarator;
    std::shared_ptr<ParameterTypeList> m_ParameterTypeList;
};

}  // namespace ast
