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
		m_expression->evaluate(ctx);
		ctx.setVariable(m_variable, ctx.loadValue().value);
	}

	void print(std::ostream& out, uint32_t i) override
	{
		indent(out, i);
		out << "ASSIGNMENT " << m_variable << std::endl;
		m_expression->print(out, i + 1);
	}

private:

	std::string m_variable;
	ASTNode m_expression;
};
