%skeleton "lalr1.cc"
%require "3.5"

%defines
%define api.token.constructor
%define api.value.type variant
%define parse.assert

%code requires {
    #include <string>
    #include <memory>

    /* Forward declaration of classes in order to disable cyclic dependencies */
    namespace clipl {
        class Lexer;
        class Driver;
    }

    #include <Clipl/Grammar/AST/ForwardDecl.hpp>

    using namespace clipl;
    using namespace ast;
}


%define parse.trace
%define parse.error verbose

%code {
    #include <Clipl/Grammar/Driver/Driver.hpp>
    #include <Clipl/Grammar/Parser/location.hh>
    #include <Clipl/Grammar/Lexer/Lexer.hpp>

    #include <Clipl/Grammar/AST/AST.hpp>

    /* Redefine parser to use our function from scanner */
    static yy::parser::symbol_type yylex(Lexer &lexer) {
        return lexer.scanToken();
    }
}

%lex-param { Lexer &lexer }

%parse-param { Lexer &lexer }
%parse-param { Driver &driver }

%locations

%define api.token.prefix {TOK_}

%token
    END 0 "end of file"
    LSBRACKET "["
    RSBRACKET "]"
    LPAREN "("
    RPAREN ")"
    LCBRACKET "{"
    RCBRACKET "}"

    ELLIPSIS "..."

    DOT "."
    ARROW "->"

    INCREMENT "++"
    DECREMENT "--"

    AMPERSAND "&"
    STAR "*"
    PLUS "+"
    MINUS "-"
    LOGICAL_NOT "~"
    NOT "!"
    SLASH "/"
    PERCENT "%"

    LTLT "<<"
    GTGT ">>"

    LT "<"
    GT ">"
    LE "<="
    GE ">="
    EQUAL "=="
    NOT_EQUAL "!="

    LOGICAL_XOR "^"
    LOGICAL_OR "|"

    AND "&&"
    OR "||"

    QUESTION "?"

    COLON ":"
    SEMICOLON ";"

    ASSIGN "="
    STAR_ASSIGN "*="
    SLASH_ASSIGN "/="
    PERCENT_ASSIGN "%="
    PLUS_ASSIGN "+="
    MINUS_ASSIGN "-="
    LTLT_ASSIGN "<<="
    GTGT_ASSIGN ">>="
    AMPERSAND_ASSIGN "&="
    XOR_ASSIGN "^="
    OR_ASSIGN "|="

    COMMA ","

    BREAK "break"
    CONTINUE "continue"

    SWITCH "switch"
    DEFAULT "default"
    CASE "case"

    VOID "void"
    CHAR "char"
    SHORT "short"
    INT "int"
    LONG "long"
    FLOAT "float"
    DOUBLE "double"

    SIGNED "signed"
    UNSIGNED "unsigned"

    CONST "const"
    VOLATILE "volatile"

    DO "do"
    FOR "for"
    WHILE "while"

    IF "if"
    ELSE "else"

    RETURN "return"

    STRUCT "struct"
    ENUM "enum"
    UNION "union"

    STATIC "static"
    EXTERN "extern"

    TYPEDEF "typedef"

    GOTO "goto"

    SIZEOF "sizeof"
;

%token <std::string> IDENTIFIER "identifier"
%token <int> NUMBER "number"


%nterm <std::shared_ptr<TranslationUnit>> translation_unit;
%nterm <std::shared_ptr<ExternalDeclaration>> external_declaration;
%nterm <std::shared_ptr<FunctionDefinition>> function_definition;
%nterm <std::shared_ptr<DeclarationSpecifiers>> declaration_specifiers;
%nterm <std::shared_ptr<IdentSpecifier>> ident_specifier;
%nterm <std::shared_ptr<IdentSpecifierList>> ident_specifier_list;
%nterm <std::shared_ptr<KeywordSpecifier>> keyword_specifier;
%nterm <std::shared_ptr<KeywordSpecifierList>> keyword_specifier_list;
%nterm <std::shared_ptr<Specifier>> specifier;
%nterm <std::shared_ptr<SpecifierList>> specifier_list;
%nterm <std::shared_ptr<StorageClassSpecifier>> storage_class_specifier;
%nterm <std::shared_ptr<TypeQualifier>> type_qualifier;
%nterm <std::shared_ptr<TypeQualifierList>> type_qualifier_list;
%nterm <std::shared_ptr<Declarator>> declarator;
%nterm <std::shared_ptr<Pointer>> pointer;
%nterm <std::shared_ptr<DirectDeclarator>> direct_declarator;
%nterm <std::shared_ptr<ParameterTypeList>> parameter_type_list;
%nterm <std::shared_ptr<ParameterList>> parameter_list;
%nterm <std::shared_ptr<ParameterDeclaration>> parameter_declaration;
%nterm <std::shared_ptr<AbstractDeclarator>> abstract_declarator;
%nterm <std::shared_ptr<DirectAbstractDeclarator>> direct_abstract_declarator;
%nterm <std::shared_ptr<ConstantExpression>> constant_expression;
%nterm <std::shared_ptr<ConditionalExpression>> conditional_expression;
%nterm <std::shared_ptr<LogicalOrExpression>> logical_or_expression;
%nterm <std::shared_ptr<LogicalAndExpression>> logical_and_expression;
%nterm <std::shared_ptr<InclusiveOrExpression>> inclusive_or_expression;
%nterm <std::shared_ptr<ExclusiveOrExpression>> exclusive_or_expression;
%nterm <std::shared_ptr<AndExpression>> and_expression;
%nterm <std::shared_ptr<EqualityExpression>> equality_expression;
%nterm <std::shared_ptr<RelationalExpression>> relational_expression;
%nterm <std::shared_ptr<ShiftExpression>> shift_expression;
%nterm <std::shared_ptr<AdditiveExpression>> additive_expression;
%nterm <std::shared_ptr<MultiplicativeExpression>> multiplicative_expression;
%nterm <std::shared_ptr<CastExpression>> cast_expression;
%nterm <std::shared_ptr<TypeName>> type_name;
%nterm <std::shared_ptr<SpecifierQualifierList>> specifier_qualifier_list;
%nterm <std::shared_ptr<UnaryExpression>> unary_expression;
%nterm <std::shared_ptr<UnaryOperator>> unary_operator;
%nterm <std::shared_ptr<PostfixExpression>> postfix_expression;
%nterm <std::shared_ptr<ArgumentExpressionList>> argument_expression_list;
%nterm <std::shared_ptr<PrimaryExpression>> primary_expression;
%nterm <std::shared_ptr<Expression>> expression;
%nterm <std::shared_ptr<AssignmentExpression>> assignment_expression;
%nterm <std::shared_ptr<AssignmentOperator>> assignment_operator;
%nterm <std::shared_ptr<CompoundStatement>> compound_statement;
%nterm <std::shared_ptr<DeclarationList>> declaration_list;
%nterm <std::shared_ptr<Declaration>> declaration;
%nterm <std::shared_ptr<InitDeclaratorList>> init_declarator_list;
%nterm <std::shared_ptr<InitDeclarator>> init_declarator;
%nterm <std::shared_ptr<InitializerList>> initializer_list;
%nterm <std::shared_ptr<Initializer>> initializer;
%nterm <std::shared_ptr<StatementList>> statement_list;
%nterm <std::shared_ptr<Statement>> statement;
%nterm <std::shared_ptr<LabeledStatement>> labeled_statement;
%nterm <std::shared_ptr<ExpressionStatement>> expression_statement;
%nterm <std::shared_ptr<SelectionStatement>> selection_statement;
%nterm <std::shared_ptr<IterationStatement>> iteration_statement;
%nterm <std::shared_ptr<JumpStatement>> jump_statement;

%nterm <std::shared_ptr<Enumerator>> enumerator;
%nterm <std::shared_ptr<EnumeratorList>> enumerator_list;
%nterm <std::shared_ptr<EnumSpecifier>> enum_specifier;

%nterm <std::shared_ptr<StructOrUnionSpecifier>> struct_or_union_specifier;
%nterm <std::shared_ptr<StructDeclaration>> struct_declaration;
%nterm <std::shared_ptr<StructDeclarationList>> struct_declaration_list;
%nterm <std::shared_ptr<StructDeclarator>> struct_declarator;
%nterm <std::shared_ptr<StructDeclaratorList>> struct_declarator_list;


// Prints output in parsing option for debugging location terminal
%printer { yyo << $$; } <*>;

%%

%start translation_unit;

translation_unit
    : external_declaration {
        $$ = std::make_shared<TranslationUnit>($1);
    }
    | external_declaration translation_unit {
        $$ = std::make_shared<TranslationUnit>($1, $2);
    };

external_declaration
    : function_definition {
        $$ = $1;
    }
    | declaration {
        $$ = $1;
    };

function_definition
    : declaration_specifiers declarator compound_statement {
        $$ = std::make_shared<FunctionDefinition>($1, $2, $3);
    }
    | declaration_specifiers error compound_statement {
        // TODO: handle error
    }
    | error compound_statement {
        // TODO: handle error
    };

declaration_specifiers
    : specifier declaration_specifiers {

    }
    | keyword_specifier_list {

    }
    | ident_specifier_list {

    };

specifier_qualifier_list
    : keyword_specifier specifier_qualifier_list {
        
    }
    | keyword_specifier {

    }
    | ident_specifier specifier_qualifier_list {

    }
    | ident_specifier {

    }
    | type_qualifier specifier_qualifier_list {

    }
    | type_qualifier {

    };

specifier
    : storage_class_specifier {

    }
    | type_qualifier {

    };

keyword_specifier_list
    : keyword_specifier {

    }
    | keyword_specifier_list keyword_specifier {

    }
    | keyword_specifier_list specifier {

    };

ident_specifier_list
    : ident_specifier {

    }
    | ident_specifier specifier_list {

    };

specifier_list
    : specifier_list specifier {

    }
    | specifier {

    };

keyword_specifier
    : "void" {
        // $$ = std::make_shared<TypeSpecifier>($1);
    }
    | "char" {
        // $$ = std::make_shared<TypeSpecifier>($1);
    }
    | "short" {
        // $$ = std::make_shared<TypeSpecifier>($1);
    }
    | "int" {
        // $$ = std::make_shared<TypeSpecifier>($1);
    }
    | "long" {
        // $$ = std::make_shared<TypeSpecifier>($1);
    }
    | "float" {
        // $$ = std::make_shared<TypeSpecifier>($1);
    }
    | "double" {
        // $$ = std::make_shared<TypeSpecifier>($1);
    }
    | "signed" {
        // $$ = std::make_shared<TypeSpecifier>($1);
    }
    | "unsigned" {
        // $$ = std::make_shared<TypeSpecifier>($1);
    }
    | struct_or_union_specifier {

    }
    | enum_specifier {

    };

struct_or_union_specifier
    : struct_or_union IDENTIFIER '{' struct_declaration_list '}' {

    }
    | struct_or_union '{' struct_declaration_list '}' {

    }
    | struct_or_union IDENTIFIER {

    }
    | struct_or_union IDENTIFIER '{' error '}' {
        // TODO: handle
    }
    | struct_or_union '{' error '}' {
        // TODO: handle error
    };

struct_or_union
    : "struct" {
        
    }
    | "union" {

    };

struct_declaration_list
    : struct_declaration {

    }
    | struct_declaration_list struct_declaration {

    };

struct_declaration
    : specifier_qualifier_list struct_declarator_list ';' {

    }
    | error ';' {
        // TODO: handle error
    };

struct_declarator_list
    : struct_declarator {

    }
    | struct_declarator_list ',' struct_declarator {

    }
    | error ',' struct_declarator {
        // TODO: handle error
    };

struct_declarator
    : declarator {

    };

enum_specifier
    : "enum" '{' enumerator_list '}' {

    }
    | "enum" IDENTIFIER '{' enumerator_list '}' {

    }
    | "enum" '{' error '}' {
        // TODO: handle error
    }
    | "enum" IDENTIFIER '{' error '}' {
        // TODO: handle error
    }
    | "enum" IDENTIFIER {

    };

enumerator_list
    : enumerator {

    }
    | enumerator_list ',' enumerator {

    }
    | error ',' enumerator {
        // TODO: handle error
    };

enumerator
    : IDENTIFIER {

    }
    | IDENTIFIER '=' constant_expression {

    }
    | error '=' constant_expression {
        // TODO: handle error
    };

storage_class_specifier
    : "typedef" {
        $$ = std::make_shared<StorageClassSpecifier>(StorageClassSpecifier::Type::kTypedef);
    }
    | "extern" {
        $$ = std::make_shared<StorageClassSpecifier>(StorageClassSpecifier::Type::kExtern);
    }
    | "static" {
        $$ = std::make_shared<StorageClassSpecifier>(StorageClassSpecifier::Type::kStatic);
    };

type_qualifier
    : "const" {
        // $$ = std::make_shared<TypeQualifier>($1);
    }
    | "volatile" {
        // $$ = std::make_shared<TypeQualifier>($1);
    };

type_qualifier_list
    : type_qualifier {

    }
    | type_qualifier_list type_qualifier {
        
    };

declarator
    : pointer direct_declarator {

    }
    | direct_declarator {

    };

pointer
    : "*" {

    }
    | "*" type_qualifier_list {

    }
    | "*" pointer {

    }
    | "*" type_qualifier_list pointer {

    }
    | "*" error pointer {
        // TODO: handle error
    };

direct_declarator
    : "identifier" {

    }
    | "(" declarator ")" {

    }
    // | "[" constant_expression "]"
    | direct_declarator "[" "]" {

    }
    | direct_declarator "(" parameter_type_list ")" {

    }
    | direct_declarator "(" ")" {

    }
    | direct_declarator "(" error ")" {
        // TODO: handle error
    }
    | error "(" error ")" {
        // TODO: handle error
    }
    | "(" error ")" {
        // TODO: handle error
    };

parameter_type_list
    : parameter_list {

    }
    | parameter_list "," "..." {

    }
    | error "," "..." {
        // TODO: handle error
    };

parameter_list
    : parameter_declaration {

    }
    | parameter_list "," parameter_declaration {

    }
    | error "," parameter_declaration {
        // TODO: handle error
    };

parameter_declaration
    : declaration_specifiers declarator {

    }
    | declaration_specifiers abstract_declarator {

    }
    | declaration_specifiers {

    };

abstract_declarator
    : pointer {

    }
    | direct_abstract_declarator {

    }
    | pointer direct_abstract_declarator {

    };

direct_abstract_declarator
    : "(" abstract_declarator ")" {

    }
    | "[" "]" {

    }
    | "[" constant_expression "]" {

    }
    | "[" error "]" {
        // TODO: handle error
    }
    | direct_abstract_declarator "[" "]" {

    }
    | direct_abstract_declarator "[" constant_expression "]" {

    }
    | "(" ")" {

    }
    | "(" parameter_type_list ")" {

    }
    | direct_abstract_declarator "(" ")" {

    }
    | direct_abstract_declarator "(" parameter_type_list ")" {

    }
    | direct_abstract_declarator "(" error ")" {
        // TODO: handle error
    }
    | direct_abstract_declarator "[" error "]" {
        // TODO: handle error
    };

constant_expression
    : conditional_expression {
        $$ = std::make_shared<ConstantExpression>($1);
    };

conditional_expression
    : logical_or_expression {
        $$ = std::make_shared<ConditionalExpression>($1);
    }
    | logical_or_expression "?" expression ":" conditional_expression {
        $$ = std::make_shared<ConditionalExpression>($1, $3, $5);
    }
    | error "?" error ":" conditional_expression {
        // TODO: handle error
    }
    | logical_or_expression "?" error ":" conditional_expression {
        // TODO: handle error
    }
    | error "?" expression ":" conditional_expression {
        // TODO: handle error
    };

logical_or_expression
    : logical_and_expression {
        $$ = std::make_shared<LogicalOrExpression>($1);
    }
    | logical_or_expression "||" logical_and_expression {
        $$ = std::make_shared<LogicalOrExpression>($1, $3);
    };

logical_and_expression
    : inclusive_or_expression {
        $$ = std::make_shared<LogicalAndExpression>($1);
    }
    | logical_and_expression "&&" inclusive_or_expression {
        $$ = std::make_shared<LogicalAndExpression>($1, $3);
    };

inclusive_or_expression
    : exclusive_or_expression {
        
    }
    | inclusive_or_expression "|" exclusive_or_expression {

    };

exclusive_or_expression
    : and_expression {

    }
    | exclusive_or_expression "^" and_expression {

    };

and_expression
    : equality_expression {

    }
    | and_expression "&" equality_expression {

    };

equality_expression
    : relational_expression {

    }
    | equality_expression "==" relational_expression {

    }
    | equality_expression "!=" relational_expression {

    }
    | error "==" relational_expression {
        // TODO: handle error
    }
    | error "!=" relational_expression {
        // TODO: handle error
    };

relational_expression
    : shift_expression {

    }
    | relational_expression "<" shift_expression {

    }
    | relational_expression ">" shift_expression {

    }
    | relational_expression "<=" shift_expression {

    }
    | relational_expression ">=" shift_expression {

    }
    | error "<" shift_expression {
        // TODO: handle error
    }
    | error ">" shift_expression {
        // TODO: handle error
    }
    | error "<=" shift_expression {
        // TODO: handle error
    }
    | error ">=" shift_expression {
        // TODO: handle error
    };

shift_expression
    : additive_expression {

    }
    | shift_expression "<<" additive_expression {

    }
    | shift_expression ">>" additive_expression {

    };

additive_expression
    : multiplicative_expression {

    }
    | additive_expression "+" multiplicative_expression {

    }
    | additive_expression "-" multiplicative_expression {

    }
    | error "+" multiplicative_expression {
        // TODO: handle error
    }
    | error '-' multiplicative_expression {
        // TODO: handle error
    };

multiplicative_expression
    : cast_expression {

    }
    | multiplicative_expression "*" cast_expression {

    }
    | multiplicative_expression "/" cast_expression {

    }
    | multiplicative_expression "%" cast_expression {

    }
    | error "*" cast_expression {
        // TODO: handle error
    }
    | error "/" cast_expression {
        // TODO: handle error
    }
    | error "%" cast_expression {
        // TODO: handle error
    };

cast_expression
    : unary_expression {

    }
    | "(" type_name ")" cast_expression {

    };

type_name
    : specifier_qualifier_list {

    }
    | specifier_qualifier_list abstract_declarator {

    };

unary_expression
    : postfix_expression {

    }
    | "++" unary_expression {

    }
    | "--" unary_expression {

    }
    | unary_operator cast_expression {

    }
    | "sizeof" unary_expression {

    }
    | "sizeof" "(" type_name ")" {

    };

unary_operator
    : "&" {
        $$ = std::make_shared<UnaryOperator>(UnaryOperator::Type::kAddress);
    }
    | "*" {
        $$ = std::make_shared<UnaryOperator>(UnaryOperator::Type::kMult);
    }
    | "+" {
        $$ = std::make_shared<UnaryOperator>(UnaryOperator::Type::kPlus);
    }
    | "-" {
        $$ = std::make_shared<UnaryOperator>(UnaryOperator::Type::kMinus);
    }
    | "~" {
        $$ = std::make_shared<UnaryOperator>(UnaryOperator::Type::kLogicalNot);
    }
    | "!" {
        $$ = std::make_shared<UnaryOperator>(UnaryOperator::Type::kNot);
    };

postfix_expression
    : primary_expression {

    }
    | postfix_expression "[" expression "]" {

    }
    | postfix_expression "(" ")" {

    }
    | postfix_expression "(" argument_expression_list ")" {

    }
    | postfix_expression "." "identifier" {

    }
    | postfix_expression "->" "identifier" {

    }
    | postfix_expression "++" {

    }
    | postfix_expression "--" {

    };

argument_expression_list
    : assignment_expression {

    }
    | argument_expression_list "," assignment_expression {

    }
    | error "," assignment_expression {
        // TODO: handle error
    };

primary_expression
    : "identifier" {

    }
    | "number" {

    }
    | '(' expression ')' {

    }
    | '(' error ')' {
        // TODO: handle error
    };
//  | STRING_LITERAL
// TODO: constants

expression
    : assignment_expression {

    }
    | expression "," assignment_expression {

    };

assignment_expression
    : conditional_expression {

    }
    | unary_expression assignment_operator assignment_expression {

    };

assignment_operator
    : "=" {
        $$ = std::make_shared<AssignmentOperator>(AssignmentOperator::Type::kAssign);
    }
    | "*=" {
        $$ = std::make_shared<AssignmentOperator>(AssignmentOperator::Type::kMulAssign);
    }
    | "/=" {
        $$ = std::make_shared<AssignmentOperator>(AssignmentOperator::Type::kDivAssign);
    }
    | "%=" {
        $$ = std::make_shared<AssignmentOperator>(AssignmentOperator::Type::kModAssign);
    }
    | "+=" {
        $$ = std::make_shared<AssignmentOperator>(AssignmentOperator::Type::kPlusAssign);
    }
    | "-=" {
        $$ = std::make_shared<AssignmentOperator>(AssignmentOperator::Type::kMinusAssign);
    }
    | "<<=" {
        $$ = std::make_shared<AssignmentOperator>(AssignmentOperator::Type::kShiftLeftAssign);
    }
    | ">>=" {
        $$ = std::make_shared<AssignmentOperator>(AssignmentOperator::Type::kShiftRightAssign);
    }
    | "&=" {
        $$ = std::make_shared<AssignmentOperator>(AssignmentOperator::Type::kLogicalAndAssign);
    }
    | "^=" {
        $$ = std::make_shared<AssignmentOperator>(AssignmentOperator::Type::kXorAssign);
    }
    | "|=" {
        $$ = std::make_shared<AssignmentOperator>(AssignmentOperator::Type::kLogicalOrAssign);
    };

compound_statement
    : "{" "}" {

    }
    | "{" statement_list "}" {

    }
    | "{" declaration_list "}" {

    }
    | "{" declaration_list statement_list "}" {

    }
    | "{" error "}" {
        // TODO: handle error
    };

declaration_list
    : declaration {

    }
    | declaration_list declaration {

    };

declaration
    : declaration_specifiers ";" {

    }
    | declaration_specifiers init_declarator_list ";" {

    }
    | declaration_specifiers init_declarator_list "=" assignment_expression ";" {

    }
    | declaration_specifiers error ";" {
        // TODO: handle error
    };

init_declarator_list
    : init_declarator {

    }
    | init_declarator_list "," init_declarator {

    }
    | error "," init_declarator {
        // TODO: handle error
    };

init_declarator
    : declarator "=" initializer {

    }
    | declarator {

    }
    | error "=" initializer {
        // TODO: handle error
    };

initializer
    : assignment_expression {

    }
    | "{" initializer_list "}" {

    }
    | "{" initializer_list "," "}" {

    }
    | "{" error "}" {
        // TODO: handle error
    };

initializer_list
    : initializer {

    }
    | initializer_list "," initializer {

    }
    | error "," initializer {
        // TODO: handle error
    };

statement_list
    : statement {

    }
    | statement_list statement {

    };

statement
    : labeled_statement {
        // $$ = $1;
    }
    | compound_statement {
        // $$ = $1; 
    }
    | expression_statement {
        // $$ = $1;
    }
    | selection_statement {
        // $$ = $1;
    }
    | iteration_statement {
        // $$ = $1;
    }
    | jump_statement {
        // $$ = $1;
    };

labeled_statement
    : "identifier" ":" statement {

    }
    | "case" constant_expression ":" statement {

    }
    | "default" ":" statement {

    };

expression_statement
    : error ";" {
        // TODO: handle error
    }
    | expression ";" {

    };

selection_statement
    : "if" "(" expression ")" statement {

    }
    | "if" "(" expression ")" statement "else" statement {

    }
    | "switch" "(" expression ")" statement {

    }
    | "if" "(" error ")" statement {
        // TODO: handle error
    }
    | "if" "(" error ")" statement "else" statement {
        // TODO: handle error
    }
    | "switch" "(" error ")" statement {
        // TODO: handle error
    };

iteration_statement
    : "while" "(" expression ")" statement {

    }
    | "do" statement "while" "(" expression ")" ";" {

    }
    | "for" "(" expression_statement expression_statement ")" statement {

    }
    | "for" "(" expression_statement expression_statement expression ")" statement {

    }
    | "do" error "while" "(" expression ")" ";" {
        // TODO: handle error
    }
    | "for" "(" error ")" statement {
        // TODO: handle error
    };

jump_statement
    : "goto" "identifier" ";" {

    }
    | "continue" ";" {

    }
    | "break" ";" {

    }
    | "return" ";" {

    }
    | "return" expression ";" {

    }
    | "return" error ";" {
        // TODO: handle error
    };

ident_specifier
    : "identifier" {

    };

%%

void yy::parser::error(const location_type& l, const std::string& m) {
    std::cerr << l << ": " << m << '\n';
}