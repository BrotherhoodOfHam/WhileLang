/*
	Syntax Error structure
*/

#pragma once

#include <ostream>
#include "wl/Tokenizer.h"

struct SyntaxError
{
	TokenCode expected = TOKEN_UNKNOWN;
	Token actual;

	SyntaxError(TokenCode ex, Token ac) :
		expected(ex),
		actual(ac)
	{}
	
	SyntaxError(const SyntaxError& rhs) :
		expected(rhs.expected),
		actual(rhs.actual)
	{}
	
	/*
		Format nice error message
	*/
	void format(std::ostream& out)
	{
		out << "Syntax Error:\n";
		out << "Expected \"" << Token::codeToString(this->expected) << "\"\n";
		out << "Actually got \"" << Token::codeToString(this->actual.code) << "\"\n";
		out << "line = " << this->actual.line << ", token num. = " << this->actual.toknum;
		out << std::endl;
	}
};
