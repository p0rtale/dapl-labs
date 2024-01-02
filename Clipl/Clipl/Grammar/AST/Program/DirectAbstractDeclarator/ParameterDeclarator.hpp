#pragma once

#include <memory>

#include <Clipl/Grammar/AST/Program/DirectAbstractDeclarator/DirectAbstractDeclarator.hpp>
#include <Clipl/Grammar/AST/Program/ParameterTypeList.hpp>


namespace ast {

class ParameterDirectAbstractDeclarator: public DirectAbstractDeclarator {
public:
    ParameterDirectAbstractDeclarator(std::shared_ptr<ParameterTypeList> parameterTypeList = nullptr)
        : m_ParameterTypeList(parameterTypeList) {}

    ParameterDirectAbstractDeclarator(std::shared_ptr<DirectAbstractDeclarator> directAbstractDeclarator,
                                      std::shared_ptr<ParameterTypeList> parameterTypeList = nullptr)
        : m_DirectAbstractDeclarator(directAbstractDeclarator),
          m_ParameterTypeList(parameterTypeList) {}

    // void accept(Visitor *visitor) override;

private:
    std::shared_ptr<DirectAbstractDeclarator> m_DirectAbstractDeclarator;
    std::shared_ptr<ParameterTypeList> m_ParameterTypeList;
};

}  // namespace ast
