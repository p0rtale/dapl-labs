#pragma once

// Base
#include <Clipl/Grammar/AST/Base/ASTNode.hpp>


// Program
#include <Clipl/Grammar/AST/Program/AbstractDeclarator.hpp>
#include <Clipl/Grammar/AST/Program/ArrayDirectAbstractDeclarator.hpp>
#include <Clipl/Grammar/AST/Program/ArrayDirectDeclarator.hpp>
#include <Clipl/Grammar/AST/Program/BasicKeywordSpecifier.hpp>
#include <Clipl/Grammar/AST/Program/Declaration.hpp>
#include <Clipl/Grammar/AST/Program/DeclarationList.hpp>
#include <Clipl/Grammar/AST/Program/DeclarationSpecifiers.hpp>
#include <Clipl/Grammar/AST/Program/Declarator.hpp>
#include <Clipl/Grammar/AST/Program/DirectAbstractDeclarator.hpp>
#include <Clipl/Grammar/AST/Program/DirectDeclarator.hpp>
#include <Clipl/Grammar/AST/Program/Enumerator.hpp>
#include <Clipl/Grammar/AST/Program/EnumeratorList.hpp>
#include <Clipl/Grammar/AST/Program/EnumSpecifier.hpp>
#include <Clipl/Grammar/AST/Program/ExternalDeclaration.hpp>
#include <Clipl/Grammar/AST/Program/FunctionDefinition.hpp>
#include <Clipl/Grammar/AST/Program/IdentDeclarationSpecifiers.hpp>
#include <Clipl/Grammar/AST/Program/IdentDirectDeclarator.hpp>
#include <Clipl/Grammar/AST/Program/IdentSpecifier.hpp>
#include <Clipl/Grammar/AST/Program/InitDeclarator.hpp>
#include <Clipl/Grammar/AST/Program/InitDeclaratorList.hpp>
#include <Clipl/Grammar/AST/Program/Initializer.hpp>
#include <Clipl/Grammar/AST/Program/InitializerList.hpp>
#include <Clipl/Grammar/AST/Program/KeywordDeclarationSpecifiers.hpp>
#include <Clipl/Grammar/AST/Program/KeywordSpecifier.hpp>
#include <Clipl/Grammar/AST/Program/NestedDirectAbstractDeclarator.hpp>
#include <Clipl/Grammar/AST/Program/NestedDirectDeclarator.hpp>
#include <Clipl/Grammar/AST/Program/ParameterDeclaration.hpp>
#include <Clipl/Grammar/AST/Program/ParameterDirectAbstractDeclarator.hpp>
#include <Clipl/Grammar/AST/Program/ParameterDirectDeclarator.hpp>
#include <Clipl/Grammar/AST/Program/ParameterList.hpp>
#include <Clipl/Grammar/AST/Program/ParameterTypeList.hpp>
#include <Clipl/Grammar/AST/Program/Pointer.hpp>
#include <Clipl/Grammar/AST/Program/Specifier.hpp>
#include <Clipl/Grammar/AST/Program/SpecifierQualifierList.hpp>
#include <Clipl/Grammar/AST/Program/StorageClassSpecifier.hpp>
#include <Clipl/Grammar/AST/Program/StructDeclaration.hpp>
#include <Clipl/Grammar/AST/Program/StructDeclarationList.hpp>
#include <Clipl/Grammar/AST/Program/StructDeclarator.hpp>
#include <Clipl/Grammar/AST/Program/StructDeclaratorList.hpp>
#include <Clipl/Grammar/AST/Program/StructOrUnionSpecifier.hpp>
#include <Clipl/Grammar/AST/Program/TranslationUnit.hpp>
#include <Clipl/Grammar/AST/Program/TypeName.hpp>
#include <Clipl/Grammar/AST/Program/TypeQualifier.hpp>
#include <Clipl/Grammar/AST/Program/TypeQualifierList.hpp>


// Expression
#include <Clipl/Grammar/AST/Expression/AccessExpression.hpp>
#include <Clipl/Grammar/AST/Expression/AdditiveExpression.hpp>
#include <Clipl/Grammar/AST/Expression/AndExpression.hpp>
#include <Clipl/Grammar/AST/Expression/ArgumentExpressionList.hpp>
#include <Clipl/Grammar/AST/Expression/AssignmentExpression.hpp>
#include <Clipl/Grammar/AST/Expression/AssignmentOperator.hpp>
#include <Clipl/Grammar/AST/Expression/CallExpression.hpp>
#include <Clipl/Grammar/AST/Expression/CastExpression.hpp>
#include <Clipl/Grammar/AST/Expression/CastTypenameExpression.hpp>
#include <Clipl/Grammar/AST/Expression/CastUnaryExpression.hpp>
#include <Clipl/Grammar/AST/Expression/ConditionalAssignmentExpression.hpp>
#include <Clipl/Grammar/AST/Expression/ConditionalExpression.hpp>
#include <Clipl/Grammar/AST/Expression/ConstantExpression.hpp>
#include <Clipl/Grammar/AST/Expression/EqualityExpression.hpp>
#include <Clipl/Grammar/AST/Expression/ExclusiveOrExpression.hpp>
#include <Clipl/Grammar/AST/Expression/Expression.hpp>
#include <Clipl/Grammar/AST/Expression/IdentPrimaryExpression.hpp>
#include <Clipl/Grammar/AST/Expression/IncDecPostfixExpression.hpp>
#include <Clipl/Grammar/AST/Expression/IncDecPrefixExpression.hpp>
#include <Clipl/Grammar/AST/Expression/InclusiveOrExpression.hpp>
#include <Clipl/Grammar/AST/Expression/IndexExpression.hpp>
#include <Clipl/Grammar/AST/Expression/LogicalAndExpression.hpp>
#include <Clipl/Grammar/AST/Expression/LogicalOrExpression.hpp>
#include <Clipl/Grammar/AST/Expression/MultiplicativeExpression.hpp>
#include <Clipl/Grammar/AST/Expression/NestedPrimaryExpression.hpp>
#include <Clipl/Grammar/AST/Expression/NumberPrimaryExpression.hpp>
#include <Clipl/Grammar/AST/Expression/OperatorUnaryExpression.hpp>
#include <Clipl/Grammar/AST/Expression/PostfixExpression.hpp>
#include <Clipl/Grammar/AST/Expression/PrimaryExpression.hpp>
#include <Clipl/Grammar/AST/Expression/RelationalExpression.hpp>
#include <Clipl/Grammar/AST/Expression/ShiftExpression.hpp>
#include <Clipl/Grammar/AST/Expression/SizeofTypenameExpression.hpp>
#include <Clipl/Grammar/AST/Expression/SizeofUnaryExpression.hpp>
#include <Clipl/Grammar/AST/Expression/UnaryAssignExpression.hpp>
#include <Clipl/Grammar/AST/Expression/UnaryExpression.hpp>
#include <Clipl/Grammar/AST/Expression/UnaryOperator.hpp>


// Statement
#include <Clipl/Grammar/AST/Statement/CaseLabeledStatement.hpp>
#include <Clipl/Grammar/AST/Statement/CompoundStatement.hpp>
#include <Clipl/Grammar/AST/Statement/DefaultLabeledStatement.hpp>
#include <Clipl/Grammar/AST/Statement/DoWhileIterationStatement.hpp>
#include <Clipl/Grammar/AST/Statement/ExpressionStatement.hpp>
#include <Clipl/Grammar/AST/Statement/ForIterationStatement.hpp>
#include <Clipl/Grammar/AST/Statement/IdentLabeledStatement.hpp>
#include <Clipl/Grammar/AST/Statement/IfSelectionStatement.hpp>
#include <Clipl/Grammar/AST/Statement/IterationStatement.hpp>
#include <Clipl/Grammar/AST/Statement/JumpStatement.hpp>
#include <Clipl/Grammar/AST/Statement/LabeledStatement.hpp>
#include <Clipl/Grammar/AST/Statement/LoopJumpStatement.hpp>
#include <Clipl/Grammar/AST/Statement/ReturnJumpStatement.hpp>
#include <Clipl/Grammar/AST/Statement/SelectionStatement.hpp>
#include <Clipl/Grammar/AST/Statement/Statement.hpp>
#include <Clipl/Grammar/AST/Statement/StatementList.hpp>
#include <Clipl/Grammar/AST/Statement/SwitchSelectionStatement.hpp>
#include <Clipl/Grammar/AST/Statement/WhileIterationStatement.hpp>
