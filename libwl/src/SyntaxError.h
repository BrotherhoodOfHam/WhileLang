/*
	Syntax Error structure
*/

#pragma once

#include <ostream>
#include "wl/Tokenizer.h"

struct SyntaxError
{
	TokenCode expected;
	TokenCode actual;

	SyntaxError() {}
	SyntaxError(TokenCode ex, TokenCode ac) :
		expected(ex),
		actual(ac)
	{}
	
	/*
		Format nice error message
	*/
	void format(std::ostream& out)
	{
		out << "Syntax Error:\n";
		out << "Expected " << Token::codeToString(expected);
		out << " actually got " << Token::codeToString(actual);
		out << std::endl;
	}
};
