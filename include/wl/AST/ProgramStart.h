/*
	Program declaration:

	<program> ::= program
					<variable-declaration-list>
				  begin
					<command-list>
				  end
*/

#pragma once

#include "wl/AST.h"

#include "VariableDeclarationList.h"
#include "CommandList.h"

class ProgramStart : public AST
{
public:

	ProgramStart(Tokenizer& tokens)
	{
		tokens.nextAssert(TOKEN_PROGRAM);

		m_vars = VariableDeclarationList(tokens);

		tokens.nextAssert(TOKEN_BEGIN);

		m_commands = CommandList(tokens);

		tokens.nextAssert(TOKEN_END);
	}

	~ProgramStart() {}

	void evaluate(Context& ctx) override
	{
		m_vars.evaluate(ctx);
		m_commands.evaluate(ctx);
	}

	void print(std::ostream& out, uint32_t i) override
	{
		indent(out, i);
		out << "PROGRAM\n";
		m_vars.print(out, i + 1);
		m_commands.print(out, i + 1);
	}

private:

	VariableDeclarationList m_vars;
	CommandList m_commands;
};
