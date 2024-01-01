#pragma once

namespace ast {

// Program
class AbstractDeclarator;
class ArrayDirectDeclarator;
class BasicKeywordSpecifier;
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
class IdentDeclarationSpecifiers;
class IdentDirectDeclarator;
class IdentSpecifier;
class InitDeclarator;
class InitDeclaratorList;
class Initializer;
class InitializerList;
class KeywordDeclarationSpecifiers;
class KeywordSpecifier;
class NestedDirectDeclarator;
class ParameterDeclaration;
class ParameterDirectDeclarator;
class ParameterList;
class ParameterTypeList;
class Pointer;
class Specifier;
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
class CaseLabeledStatement;
class CompoundStatement;
class DefaultLabeledStatement;
class DoWhileIterationStatement;
class ExpressionStatement;
class ForIterationStatement;
class IdentLabeledStatement;
class IfSelectionStatement;
class IterationStatement;
class JumpStatement;
class LabeledStatement;
class LoopJumpStatement;
class ReturnJumpStatement;
class SelectionStatement;
class Statement;
class StatementList;
class SwitchSelectionStatement;
class WhileIterationStatement;

}  // namespace ast
