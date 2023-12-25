#pragma once

#include <Clipl/Grammar/Parser/Parser.hpp>

namespace clipl {

#undef YY_DECL
#define YY_DECL yy::parser::symbol_type Lexer::scanToken()

class Driver;

class Lexer: public cliplFlexLexer {
 public:
    Lexer(Driver& driver): m_Driver(driver) {}
	virtual ~Lexer() {}

	virtual yy::parser::symbol_type scanToken();

    Driver& m_Driver;
};

}  // namespace clipl
