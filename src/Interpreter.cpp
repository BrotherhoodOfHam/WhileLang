/*
	Interpreter class
*/

#include <iostream>

#include "wl/Interpreter.h"
#include "wl/SyntaxError.h"

#include "wl/AST/ProgramStart.h"

////////////////////////////////////////////////////////////////////////////////////////////////

WLInterpreter::WLInterpreter(std::istream& program) :
	m_tokens(program)
{
	//default logger is STDOUT
	m_log = &std::cout;
}

ExitCode WLInterpreter::execute()
{
	try
	{
		//Build Abstract Syntax Tree
		m_syntaxTree.reset(new ProgramStart(m_tokens));

		std::cout << "-------- Abstract Syntax Tree --------\n";

		//Print tree
		m_syntaxTree->print(std::cout);

		std::cout << "------------- Executing --------------\n";
		
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
