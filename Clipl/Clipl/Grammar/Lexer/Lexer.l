%{
    #include <cerrno>
    #include <climits>
    #include <cstdlib>
    #include <string>
    #include <iostream>
    #include <format>

    #include <Clipl/Grammar/Lexer/LexerInternal.hpp>
    #include <Clipl/Grammar/Parser/Parser.hpp>
    #include <Clipl/Grammar/Driver/Driver.hpp>

    using namespace clipl;

    // Escape sequences
    // https://learn.microsoft.com/ru-ru/cpp/c-language/escape-sequences?view=msvc-170
%}

%option noyywrap nounput noinput batch debug

%option c++
%option prefix="clipl"
%option yyclass="Lexer"

%{
    yy::parser::symbol_type make_INTEGER_CONSTANT(
        const std::string& s,
        const yy::parser::location_type& loc
    );

    yy::parser::symbol_type make_REAL_CONSTANT(
        const std::string& s,
        const yy::parser::location_type& loc
    );
%}

identifier  [a-zA-Z_][a-zA-Z_0-9]*

hex_base    (0[xX])
hex_digit   [a-fA-F0-9]
octal_digit [0-7]
digit       [0-9]
no_zero     [1-9]
exp         ([Ee][+-]?{digit}+)
hex_exp     ([Pp][+-]?{digit}+)

blank      [ \t\r]
whitespace [ \t\n]
escape     (\\(['"\?\\abfnrtv]|[0-7]{1,3}|x[a-fA-F0-9]+))

%{
    #define YY_USER_ACTION  loc.columns(yyleng);
%}

%%
%{
    yy::location& loc = m_Driver.getLocation();
    loc.step();
%}

{blank}+   loc.step();
\n+        loc.lines(yyleng); loc.step();

"["        return yy::parser::make_LSBRACKET(loc);
"]"        return yy::parser::make_RSBRACKET(loc);
"("        return yy::parser::make_LPAREN(loc);
")"        return yy::parser::make_RPAREN(loc);
"{"        return yy::parser::make_LCBRACKET(loc);
"}"        return yy::parser::make_RCBRACKET(loc);

"..."      return yy::parser::make_ELLIPSIS(loc);

"."        return yy::parser::make_DOT(loc);
"->"       return yy::parser::make_ARROW(loc);

"++"       return yy::parser::make_INCREMENT(loc);
"--"       return yy::parser::make_DECREMENT(loc);

"*="       return yy::parser::make_STAR_ASSIGN(loc);
"/="       return yy::parser::make_SLASH_ASSIGN(loc);
"%="       return yy::parser::make_PERCENT_ASSIGN(loc);
"+="       return yy::parser::make_PLUS_ASSIGN(loc);
"-="       return yy::parser::make_MINUS_ASSIGN(loc);
"<<="      return yy::parser::make_LTLT_ASSIGN(loc);
">>="      return yy::parser::make_GTGT_ASSIGN(loc);
"&="       return yy::parser::make_AMPERSAND_ASSIGN(loc);
"^="       return yy::parser::make_XOR_ASSIGN(loc);
"|="       return yy::parser::make_OR_ASSIGN(loc);

"&"        return yy::parser::make_AMPERSAND(loc);
"*"        return yy::parser::make_STAR(loc);
"+"        return yy::parser::make_PLUS(loc);
"-"        return yy::parser::make_MINUS(loc);
"~"        return yy::parser::make_LOGICAL_NOT(loc);
"!"        return yy::parser::make_NOT(loc);
"/"        return yy::parser::make_SLASH(loc);
"%"        return yy::parser::make_PERCENT(loc);

"<<"       return yy::parser::make_LTLT(loc);
">>"       return yy::parser::make_GTGT(loc);

"<="       return yy::parser::make_LE(loc);
">="       return yy::parser::make_GE(loc);
"<"        return yy::parser::make_LT(loc);
">"        return yy::parser::make_GT(loc);
"=="       return yy::parser::make_EQUAL(loc);
"!="       return yy::parser::make_NOT_EQUAL(loc);

"&&"       return yy::parser::make_AND(loc);
"||"       return yy::parser::make_OR(loc);

"^"        return yy::parser::make_LOGICAL_XOR(loc);
"|"        return yy::parser::make_LOGICAL_OR(loc);

"?"        return yy::parser::make_QUESTION(loc);

":"        return yy::parser::make_COLON(loc);
";"        return yy::parser::make_SEMICOLON(loc);

"="        return yy::parser::make_ASSIGN(loc);

","        return yy::parser::make_COMMA(loc);

"break"    return yy::parser::make_BREAK(loc);
"continue" return yy::parser::make_CONTINUE(loc);

"switch"   return yy::parser::make_SWITCH(loc);
"default"  return yy::parser::make_DEFAULT(loc);
"case"     return yy::parser::make_CASE(loc);

"void"     return yy::parser::make_VOID(loc);
"char"     return yy::parser::make_CHAR(loc);
"short"    return yy::parser::make_SHORT(loc);
"int"      return yy::parser::make_INT(loc);
"long"     return yy::parser::make_LONG(loc);
"float"    return yy::parser::make_FLOAT(loc);
"double"   return yy::parser::make_DOUBLE(loc);

"signed"   return yy::parser::make_SIGNED(loc);
"unsigned" return yy::parser::make_UNSIGNED(loc);

"const"    return yy::parser::make_CONST(loc);
"volatile" return yy::parser::make_VOLATILE(loc);

"do"       return yy::parser::make_DO(loc);
"for"      return yy::parser::make_FOR(loc);
"while"    return yy::parser::make_WHILE(loc);

"if"       return yy::parser::make_IF(loc);
"else"     return yy::parser::make_ELSE(loc);

"return"   return yy::parser::make_RETURN(loc);

"struct"   return yy::parser::make_STRUCT(loc);
"enum"     return yy::parser::make_ENUM(loc);
"union"    return yy::parser::make_UNION(loc);

"static"   return yy::parser::make_STATIC(loc);
"extern"   return yy::parser::make_EXTERN(loc);

"typedef"  return yy::parser::make_TYPEDEF(loc); 

"goto"     return yy::parser::make_GOTO(loc);

"sizeof"   return yy::parser::make_SIZEOF(loc);

(\"([^"\\\n]|{escape})*\"{whitespace}*)+   return yy::parser::make_STRING_LITERAL(yytext, loc);

{identifier}    return yy::parser::make_IDENTIFIER(yytext, loc);

{hex_base}{hex_digit}+         return make_INTEGER_CONSTANT(yytext, loc);
{no_zero}{digit}*              return make_INTEGER_CONSTANT(yytext, loc);
"0"{octal_digit}*              return make_INTEGER_CONSTANT(yytext, loc);
"'"([^'\\\n]|{escape})+"'"     return make_INTEGER_CONSTANT(yytext, loc);

{digit}+{exp}                                     return make_REAL_CONSTANT(yytext, loc);
{digit}*"."{digit}+{exp}?                         return make_REAL_CONSTANT(yytext, loc);
{digit}+"."{exp}?                                 return make_REAL_CONSTANT(yytext, loc);
{hex_base}{hex_digit}+{hex_exp}                   return make_REAL_CONSTANT(yytext, loc);
{hex_base}{hex_digit}*"."{hex_digit}+{hex_exp}    return make_REAL_CONSTANT(yytext, loc);
{hex_base}{hex_digit}+"."{hex_exp}                return make_REAL_CONSTANT(yytext, loc);

.          throw yy::parser::syntax_error(loc, "invalid character: " + std::string(yytext));

<<EOF>>    return yy::parser::make_END(loc);
%%

yy::parser::symbol_type make_INTEGER_CONSTANT(const std::string &str,
                                              const yy::parser::location_type& loc) {
    errno = 0;
    char* endPtr = nullptr;
    const char* integerPtr = str.c_str();
    long integer = std::strtol(integerPtr, &endPtr, 0);
    if (integerPtr == endPtr) {
        throw yy::parser::syntax_error(loc, std::format("invalid integer constant \"{}\"", str));
    }
    if (errno == ERANGE) {
        throw yy::parser::syntax_error(loc, std::format("integer constant \"{}\" is out of range", str));
    }
    if (errno != 0 && integer == 0) {
        throw yy::parser::syntax_error(loc, std::format("invalid integer constant \"{}\"", str));
    }
    if (errno == 0 && *endPtr == 0) {
        return yy::parser::make_INTEGER_CONSTANT(static_cast<int>(integer), loc);
    }
    throw yy::parser::syntax_error(loc, std::format("invalid integer constant \"{}\"", str));
}

yy::parser::symbol_type make_REAL_CONSTANT(const std::string &str,
                                           const yy::parser::location_type& loc) {
    errno = 0;
    char* endPtr = nullptr;
    const char* realPtr = str.c_str();
    float real = std::strtof(realPtr, &endPtr);
    if (realPtr == endPtr) {
        throw yy::parser::syntax_error(loc, std::format("invalid real number constant \"{}\"", str));
    }
    if (errno == ERANGE) {
        throw yy::parser::syntax_error(loc, std::format("real number constant \"{}\" is out of range", str));
    }
    if (errno != 0 && real == 0) {
        throw yy::parser::syntax_error(loc, std::format("invalid real number constant \"{}\"", str));
    }
    if (errno == 0 && *endPtr == 0) {
        return yy::parser::make_REAL_CONSTANT(real, loc);
    }
    throw yy::parser::syntax_error(loc, std::format("invalid real number constant \"{}\"", str));
}
