/*
	ExpressionBuilder:
	
	<expression> ::= <literal>
	<expression> ::= <variable>
	<expression> ::= (<expression>)
	<expression> ::= <operation>
*/

#pragma once

#include "wl/AST.h"

class ExpressionBuilder
{
public:
	
	static ASTNode construct(Tokenizer& tokens);
	
private:

	ExpressionBuilder() {}
};
