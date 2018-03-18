/*
	IO Read Statement:

	<io-read-command> ::= read ( <identifier-list> )
*/

#pragma once

#include "wl/AST.h"

class IOReadCommand : public AST
{
public:

	IOReadCommand(Tokenizer& tokens)
	{
		tokens.nextAssert(TOKEN_READ);
		tokens.nextAssert(TOKEN_OPEN_BRACKET);

		while (!tokens.isNext(TOKEN_CLOSE_BRACKET))
		{
			m_variables.push_back(tokens.nextAssert(TOKEN_IDENTIFIER).symbol);
			
			if (tokens.isNext(TOKEN_COMMA))
			{
				tokens.next();
			}
			else
			{
				break;
			}
		}

		tokens.nextAssert(TOKEN_CLOSE_BRACKET);
	}

	void evaluate(Context& ctx) override
	{

	}

private:

	std::vector<std::string> m_variables;
};
