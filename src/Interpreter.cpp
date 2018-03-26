/*
	Interpreter class
*/

#include <iostream>

#include "wl/Interpreter.h"
#include "wl/Tokenizer.h"
#include "wl/SyntaxError.h"

#include "wl/AST/ProgramStart.h"

////////////////////////////////////////////////////////////////////////////////////////////////

WLInterpreter::WLInterpreter()
{
	//default logger is STDOUT
	m_log = &std::cout;
}

bool WLInterpreter::build(std::istream& program)
{
	Tokenizer tokens(program);
	
	try
	{
		//Build Abstract Syntax Tree
		m_syntaxTree.reset(new ProgramStart(tokens));
	}
	catch (SyntaxError e)
	{
		e.format(log());
		return false;
	}
	
	return true;
}

void WLInterpreter::print()
{
	//Print tree
	if (m_syntaxTree == nullptr)
	{
		log() << "EMPTY";
	}
	else
	{
		m_syntaxTree->print(log());
	}
}

ExitCode WLInterpreter::execute()
{
	if (m_syntaxTree == nullptr)
	{
		return EX_ERROR;
	}
	
	try
	{
		//Execute program
		m_syntaxTree->evaluate(m_ctx);
	}
	catch (SyntaxError e)
	{
		e.format(log());
		return EX_ERROR;
	}

	return EX_SUCCESS;
}

////////////////////////////////////////////////////////////////////////////////////////////////
