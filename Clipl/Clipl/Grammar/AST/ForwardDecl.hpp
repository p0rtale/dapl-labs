#pragma once

namespace ast {

// Program
class AbstractDeclarator;
class Declaration;
class DeclarationList;
class DeclarationSpecifiers;
class Declarator;
class DirectAbstractDeclarator;
class DirectDeclarator;
class Enumerator;
class EnumeratorList;
class EnumSpecifier;
class ExternalDeclaration;
class FunctionDefinition;
class IdentSpecifier;
class IdentSpecifierList;
class InitDeclarator;
class InitDeclaratorList;
class Initializer;
class InitializerList;
class KeywordSpecifier;
class KeywordSpecifierList;
class ParameterDeclaration;
class ParameterList;
class ParameterTypeList;
class Pointer;
class Specifier;
class SpecifierList;
class SpecifierQualifierList;
class StorageClassSpecifier;
class StructDeclaration;
class StructDeclarationList;
class StructDeclarator;
class StructDeclaratorList;
class StructOrUnionSpecifier;
class TranslationUnit;
class TypeName;
class TypeQualifier;
class TypeQualifierList;


// Expression
class AdditiveExpression;
class AndExpression;
class ArgumentExpressionList;
class AssignmentExpression;
class AssignmentOperator;
class CastExpression;
class ConditionalExpression;
class ConstantExpression;
class EqualityExpression;
class ExclusiveOrExpression;
class Expression;
class InclusiveOrExpression;
class LogicalAndExpression;
class LogicalOrExpression;
class MultiplicativeExpression;
class PostfixExpression;
class PrimaryExpression;
class RelationalExpression;
class ShiftExpression;
class UnaryExpression;
class UnaryOperator;


// Statement
class CompoundStatement;
class ExpressionStatement;
class IterationStatement;
class JumpStatement;
class LabeledStatement;
class SelectionStatement;
class Statement;
class StatementList;


}  // namespace ast
