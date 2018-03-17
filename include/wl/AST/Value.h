/*
	Value
	
	<value> ::= <boolean> | <integer> | <identifier>
*/

#pragma once

#include "wl/AST.h"

class Value : public AST
{
public:

	static bool hasNext(Tokenizer& tokens)
	{
		switch (tokens.peek().code)
		{
			case TOKEN_BOOL:       return true;
			case TOKEN_INTEGER:    return true;
			case TOKEN_IDENTIFIER: return true;
		}

		return false;
	}

	Value(Tokenizer& tokens)
	{
		Token tok = tokens.next();
		switch (tok.code)
		{
		case TOKEN_BOOL:       m_isVar = false;  m_value = tok.symbol; return;
		case TOKEN_INTEGER:    m_isVar = false;  m_value = tok.symbol; return;
		case TOKEN_IDENTIFIER: m_isVar = true;   m_value = tok.symbol; return;
		default: throw SyntaxError(TOKEN_IDENTIFIER, tok.code);
		}
	}

	void evaluate(Context& ctx) override
	{

	}

private:

	bool m_isVar;
	std::string m_value;
};
