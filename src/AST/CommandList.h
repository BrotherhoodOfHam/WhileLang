/*
	Command List:


*/

#pragma once

#include "Command.h"

class CommandList : public AST
{
public:

	CommandList() {}
	~CommandList() {}

	CommandList(Tokenizer& tokens)
	{

	}

	void evalutate(Context& ctx) override
	{

	}

private:

	std::vector<Command*> m_commands;
};
