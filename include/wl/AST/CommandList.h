/*
	Command List:

	<command-list> ::= <command>; | <command>; <command-list>
*/

#pragma once

#include "CommandBuilder.h"

class CommandList : public AST
{
public:

	CommandList() {}
	~CommandList() {}

	CommandList(Tokenizer& tokens)
	{
		while (CommandBuilder::hasNext(tokens))
		{
			m_commands.emplace_back(CommandBuilder::construct(tokens));
			tokens.nextAssert(TOKEN_SEPARATOR);
		}
	}

	void evaluate(Context& ctx) override
	{
		for (auto& cmd : m_commands)
		{
			cmd->evaluate(ctx);
		}
	}

	void print(std::ostream& out, uint32_t i) override
	{
		indent(out, i);
		out << "COMMAND-LIST:" << std::endl;
		for (auto& cmd : m_commands)
		{
			cmd->print(out, i + 1);
		}
	}

private:

	ASTNodeList m_commands;
};
