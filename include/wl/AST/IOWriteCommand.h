/*
	IO Write Statement:

	<expression-list> ::= <expression> | <expression>, <expression-list>
	<io-write-command> ::= write ( <expression-list> )
*/

#pragma once

#include "wl/AST.h"

#include "ExpressionBuilder.h"

class IOWriteCommand : public AST
{
public:

	IOWriteCommand(Tokenizer& tokens)
	{
		tokens.nextAssert(TOKEN_WRITE);
		tokens.nextAssert(TOKEN_OPEN_BRACKET);

		while (!tokens.isNext(TOKEN_CLOSE_BRACKET))
		{
			m_expressions.emplace_back(ExpressionBuilder::construct(tokens));
			
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

	void print(std::ostream& out, uint32_t i) override
	{
		indent(out, i);
		out << "IO-WRITE" << std::endl;

		for (auto& node : m_expressions)
		{
			node->print(out, i + 1);
		}
	}

private:
	
	ASTNodeList m_expressions;
};
