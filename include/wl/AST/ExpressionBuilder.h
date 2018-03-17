/*
	ExpressionBuilder:
	
	<expression> ::= <value>
	<expression> ::= (<expression>)
	<expression> ::= <expression> <operator> <expression>
*/

#pragma once

#include "wl/AST.h"

#include "Value.h"

class ExpressionBuilder
{
public:
	
	static ASTNode construct(Tokenizer& tokens)
	{
		if (tokens.isNext(TOKEN_OPEN_BRACKET))
		{

		}
		else if (Value::hasNext(tokens))
		{

		}
		
		return ASTNode(nullptr);
	}
	
private:

	ExpressionBuilder() {}
};
