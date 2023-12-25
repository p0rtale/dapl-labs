#pragma once

#include <Clipl/Preprocessor/Lexer/Token.hpp>

namespace preprocessor {

#undef YY_DECL
#define YY_DECL Token Lexer::scanToken()

class Lexer: public preFlexLexer {
public:
    using preFlexLexer::preFlexLexer;
	virtual ~Lexer() = default;

	virtual Token scanToken();
};

}  // namespace preprocessor
