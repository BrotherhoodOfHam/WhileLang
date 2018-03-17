/*
	Assignment Statement:

	<identifier> := <expression>
*/

#pragma once

#include "wl/AST.h"

#include "ExpressionBuilder.h"

class AssignmentStatement : public AST
{
public:

	AssignmentStatement(Tokenizer& tokens)
	{
		m_variable = tokens.nextAssert(TOKEN_IDENTIFIER).symbol;
		tokens.nextAssert(TOKEN_ASSIGN);
		m_expression = ExpressionBuilder::construct(tokens);
	}

	void evaluate(Context& ctx) override
	{

	}

private:

	std::string m_variable;
	ASTNode m_expression;
};
