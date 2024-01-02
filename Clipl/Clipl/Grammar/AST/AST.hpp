#pragma once

/*
=====================================================================
                              Base
=====================================================================
*/
#include <Clipl/Grammar/AST/Base/ASTNode.hpp>


/*
=====================================================================
                             Program
=====================================================================
*/

// Declaration specifiers
#include <Clipl/Grammar/AST/Program/DeclarationSpecifiers/DeclarationSpecifiers.hpp>
#include <Clipl/Grammar/AST/Program/DeclarationSpecifiers/IdentDeclarationSpecifiers.hpp>
#include <Clipl/Grammar/AST/Program/DeclarationSpecifiers/KeywordDeclarationSpecifiers.hpp>

// Declarator
#include <Clipl/Grammar/AST/Program/Declarator/AbstractDeclarator.hpp>
#include <Clipl/Grammar/AST/Program/Declarator/BaseDeclarator.hpp>
#include <Clipl/Grammar/AST/Program/Declarator/Declarator.hpp>

// Direct abstract declarator
#include <Clipl/Grammar/AST/Program/DirectAbstractDeclarator/ArrayDeclarator.hpp>
#include <Clipl/Grammar/AST/Program/DirectAbstractDeclarator/DirectAbstractDeclarator.hpp>
#include <Clipl/Grammar/AST/Program/DirectAbstractDeclarator/NestedDeclarator.hpp>
#include <Clipl/Grammar/AST/Program/DirectAbstractDeclarator/ParameterDeclarator.hpp>

// Direct declarator
#include <Clipl/Grammar/AST/Program/DirectDeclarator/ArrayDeclarator.hpp>
#include <Clipl/Grammar/AST/Program/DirectDeclarator/DirectDeclarator.hpp>
#include <Clipl/Grammar/AST/Program/DirectDeclarator/IdentDeclarator.hpp>
#include <Clipl/Grammar/AST/Program/DirectDeclarator/NestedDeclarator.hpp>
#include <Clipl/Grammar/AST/Program/DirectDeclarator/ParameterDeclarator.hpp>

// External declaration
#include <Clipl/Grammar/AST/Program/ExternalDeclaration/Declaration.hpp>
#include <Clipl/Grammar/AST/Program/ExternalDeclaration/ExternalDeclaration.hpp>
#include <Clipl/Grammar/AST/Program/ExternalDeclaration/FunctionDefinition.hpp>

// Initializer
#include <Clipl/Grammar/AST/Program/Initializer/ExpressionInitializer.hpp>
#include <Clipl/Grammar/AST/Program/Initializer/Initializer.hpp>
#include <Clipl/Grammar/AST/Program/Initializer/InitializerList.hpp>

// Keyword specifier
#include <Clipl/Grammar/AST/Program/KeywordSpecifier/BasicKeywordSpecifier.hpp>
#include <Clipl/Grammar/AST/Program/KeywordSpecifier/EnumSpecifier.hpp>
#include <Clipl/Grammar/AST/Program/KeywordSpecifier/KeywordSpecifier.hpp>
#include <Clipl/Grammar/AST/Program/KeywordSpecifier/StructOrUnionSpecifier.hpp>

// Specifier
#include <Clipl/Grammar/AST/Program/Specifier/Specifier.hpp>
#include <Clipl/Grammar/AST/Program/Specifier/StorageClassSpecifier.hpp>
#include <Clipl/Grammar/AST/Program/Specifier/TypeQualifier.hpp>

#include <Clipl/Grammar/AST/Program/Enumerator.hpp>
#include <Clipl/Grammar/AST/Program/IdentSpecifier.hpp>
#include <Clipl/Grammar/AST/Program/InitDeclarator.hpp>
#include <Clipl/Grammar/AST/Program/ParameterDeclaration.hpp>
#include <Clipl/Grammar/AST/Program/ParameterTypeList.hpp>
#include <Clipl/Grammar/AST/Program/Pointer.hpp>
#include <Clipl/Grammar/AST/Program/Program.hpp>
#include <Clipl/Grammar/AST/Program/SpecifierQualifierList.hpp>
#include <Clipl/Grammar/AST/Program/StructDeclaration.hpp>
#include <Clipl/Grammar/AST/Program/StructDeclarator.hpp>
#include <Clipl/Grammar/AST/Program/TypeName.hpp>


/*
=====================================================================
                            Expression
=====================================================================
*/

// Assignment expression
#include <Clipl/Grammar/AST/Expression/AssignmentExpression/AssignmentExpression.hpp>
#include <Clipl/Grammar/AST/Expression/AssignmentExpression/ConditionalExpression.hpp>
#include <Clipl/Grammar/AST/Expression/AssignmentExpression/UnaryAssignExpression.hpp>

// Cast expression
#include <Clipl/Grammar/AST/Expression/CastExpression/CastExpression.hpp>
#include <Clipl/Grammar/AST/Expression/CastExpression/CastTypenameExpression.hpp>
#include <Clipl/Grammar/AST/Expression/CastExpression/CastUnaryExpression.hpp>

// Postfix expression
#include <Clipl/Grammar/AST/Expression/PostfixExpression/AccessExpression.hpp>
#include <Clipl/Grammar/AST/Expression/PostfixExpression/CallExpression.hpp>
#include <Clipl/Grammar/AST/Expression/PostfixExpression/IncDecPostfixExpression.hpp>
#include <Clipl/Grammar/AST/Expression/PostfixExpression/IndexExpression.hpp>
#include <Clipl/Grammar/AST/Expression/PostfixExpression/PostfixExpression.hpp>

// Primary expression
#include <Clipl/Grammar/AST/Expression/PrimaryExpression/IdentPrimaryExpression.hpp>
#include <Clipl/Grammar/AST/Expression/PrimaryExpression/NestedPrimaryExpression.hpp>
#include <Clipl/Grammar/AST/Expression/PrimaryExpression/NumberPrimaryExpression.hpp>
#include <Clipl/Grammar/AST/Expression/PrimaryExpression/PrimaryExpression.hpp>

// Unary expression
#include <Clipl/Grammar/AST/Expression/UnaryExpression/IncDecPrefixExpression.hpp>
#include <Clipl/Grammar/AST/Expression/UnaryExpression/OperatorUnaryExpression.hpp>
#include <Clipl/Grammar/AST/Expression/UnaryExpression/SizeofTypenameExpression.hpp>
#include <Clipl/Grammar/AST/Expression/UnaryExpression/SizeofUnaryExpression.hpp>
#include <Clipl/Grammar/AST/Expression/UnaryExpression/UnaryExpression.hpp>

#include <Clipl/Grammar/AST/Expression/AdditiveExpression.hpp>
#include <Clipl/Grammar/AST/Expression/AndExpression.hpp>
#include <Clipl/Grammar/AST/Expression/AssignmentOperator.hpp>
#include <Clipl/Grammar/AST/Expression/ConditionalExpression.hpp>
#include <Clipl/Grammar/AST/Expression/ConstantExpression.hpp>
#include <Clipl/Grammar/AST/Expression/EqualityExpression.hpp>
#include <Clipl/Grammar/AST/Expression/ExclusiveOrExpression.hpp>
#include <Clipl/Grammar/AST/Expression/Expression.hpp>
#include <Clipl/Grammar/AST/Expression/InclusiveOrExpression.hpp>
#include <Clipl/Grammar/AST/Expression/LogicalAndExpression.hpp>
#include <Clipl/Grammar/AST/Expression/LogicalOrExpression.hpp>
#include <Clipl/Grammar/AST/Expression/MultiplicativeExpression.hpp>
#include <Clipl/Grammar/AST/Expression/RelationalExpression.hpp>
#include <Clipl/Grammar/AST/Expression/ShiftExpression.hpp>
#include <Clipl/Grammar/AST/Expression/UnaryOperator.hpp>


/*
=====================================================================
                             Statement
=====================================================================
*/

// Iteration statement
#include <Clipl/Grammar/AST/Statement/IterationStatement/DoWhileIterationStatement.hpp>
#include <Clipl/Grammar/AST/Statement/IterationStatement/ForIterationStatement.hpp>
#include <Clipl/Grammar/AST/Statement/IterationStatement/IterationStatement.hpp>
#include <Clipl/Grammar/AST/Statement/IterationStatement/WhileIterationStatement.hpp>

// Jump statement
#include <Clipl/Grammar/AST/Statement/JumpStatement/JumpStatement.hpp>
#include <Clipl/Grammar/AST/Statement/JumpStatement/LoopJumpStatement.hpp>
#include <Clipl/Grammar/AST/Statement/JumpStatement/ReturnJumpStatement.hpp>

// Labeled statement
#include <Clipl/Grammar/AST/Statement/LabeledStatement/CaseLabeledStatement.hpp>
#include <Clipl/Grammar/AST/Statement/LabeledStatement/DefaultLabeledStatement.hpp>
#include <Clipl/Grammar/AST/Statement/LabeledStatement/IdentLabeledStatement.hpp>
#include <Clipl/Grammar/AST/Statement/LabeledStatement/LabeledStatement.hpp>

// Selection statement
#include <Clipl/Grammar/AST/Statement/SelectionStatement/IfSelectionStatement.hpp>
#include <Clipl/Grammar/AST/Statement/SelectionStatement/SelectionStatement.hpp>
#include <Clipl/Grammar/AST/Statement/SelectionStatement/SwitchSelectionStatement.hpp>

#include <Clipl/Grammar/AST/Statement/CompoundStatement.hpp>
#include <Clipl/Grammar/AST/Statement/ExpressionStatement.hpp>
#include <Clipl/Grammar/AST/Statement/Statement.hpp>
