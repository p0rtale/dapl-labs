#pragma once

#include <Clipl/Grammar/AST/Program/DirectAbstractDeclarator/DirectAbstractDeclarator.hpp>
#include <Clipl/Grammar/AST/Program/ParameterTypeList.hpp>


namespace ast {

class ParameterDirectAbstractDeclarator: public DirectAbstractDeclarator {
public:
    ParameterDirectAbstractDeclarator(RefT<ParameterTypeList> parameterTypeList = nullptr)
        : m_ParameterTypeList(parameterTypeList) {}

    ParameterDirectAbstractDeclarator(RefT<DirectAbstractDeclarator> directAbstractDeclarator,
                                      RefT<ParameterTypeList> parameterTypeList = nullptr)
        : m_DirectAbstractDeclarator(directAbstractDeclarator),
          m_ParameterTypeList(parameterTypeList) {}

    // void accept(Visitor *visitor) override;

private:
    RefT<DirectAbstractDeclarator> m_DirectAbstractDeclarator;
    RefT<ParameterTypeList> m_ParameterTypeList;
};

}  // namespace ast
