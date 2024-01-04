#pragma once

namespace ast {

// Program
class AbstractDeclarator;
class ArrayDirectAbstractDeclarator;
class ArrayDirectDeclarator;
class BaseDeclarator;
class BasicKeywordSpecifier;
class Declaration;
class DeclarationSpecifiers;
class Declarator;
class DirectAbstractDeclarator;
class DirectDeclarator;
class Enumerator;
class EnumSpecifier;
class ExpressionInitializer;
class ExternalDeclaration;
class FunctionDefinition;
class IdentDeclarationSpecifiers;
class IdentDirectDeclarator;
class IdentSpecifier;
class InitDeclarator;
class Initializer;
class InitializerList;
class KeywordDeclarationSpecifiers;
class KeywordSpecifier;
class NestedDirectAbstractDeclarator;
class NestedDirectDeclarator;
class ParameterDeclaration;
class ParameterDirectAbstractDeclarator;
class ParameterDirectDeclarator;
class ParameterTypeList;
class Pointer;
class Program;
class Specifier;
class SpecifierQualifierList;
class StorageClassSpecifier;
class StructDeclaration;
class StructDeclarator;
enum class StructOrUnionType;
class StructOrUnionSpecifier;
class TypeName;
class TypeQualifier;


// Expression
class AccessExpression;
class AdditiveExpression;
class AndExpression;
class AssignmentExpression;
class AssignmentOperator;
class CallExpression;
class CastExpression;
class CastTypenameExpression;
class CastUnaryExpression;
class ConditionalAssignmentExpression;
class ConditionalExpression;
class ConstantExpression;
class EqualityExpression;
class ExclusiveOrExpression;
class Expression;
class IdentPrimaryExpression;
class IncDecPostfixExpression;
class IncDecPrefixExpression;
class InclusiveOrExpression;
class IndexExpression;
class LogicalAndExpression;
class LogicalOrExpression;
class MultiplicativeExpression;
class NestedPrimaryExpression;
class NumberPrimaryExpression;
class OperatorUnaryExpression;
class PostfixExpression;
class PrimaryExpression;
class RelationalExpression;
class ShiftExpression;
class SizeofTypenameExpression;
class SizeofUnaryExpression;
class UnaryAssignExpression;
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
class SwitchSelectionStatement;
class WhileIterationStatement;

}  // namespace ast
