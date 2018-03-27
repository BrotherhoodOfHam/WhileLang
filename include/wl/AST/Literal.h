/*
	Literal
	
	<literal> ::= <boolean> | <integer>
*/

#pragma once

#include <string>

#include "wl/AST.h"
#include "wl/SyntaxError.h"

class Literal : public AST
{
public:

	static bool hasNext(Tokenizer& tokens)
	{
		switch (tokens.peek().code)
		{
			case TOKEN_BOOL:       return true;
			case TOKEN_INTEGER:    return true;
		}

		return false;
	}

	Literal(Tokenizer& tokens)
	{
		Token tok = tokens.next();
		
		switch (tok.code)
		{
		case TOKEN_BOOL:
			m_literal.type = TypeID::BOOL;
			m_literal.value = (tok.symbol == "false") ? 0 : 1;
			return;
		case TOKEN_INTEGER:
			m_literal.type = TypeID::NAT;
			m_literal.value = std::stoull(tok.symbol);
			return;
		}
		
		throw SyntaxError(TOKEN_INTEGER, tok);
	}

	void evaluate(Context& ctx) override
	{
		ctx.storeValue(m_literal);
	}

	void print(std::ostream& out, uint32_t i) override
	{
		indent(out, i);
		out << "LITERAL " << m_literal.value << std::endl;
	}

private:

	Context::Variable m_literal;
};
