/*
	WhileLang interpreter class

	Evaluates and executes a given WhileLang program.
*/

#pragma once

#include <istream>
#include <ostream>
#include <memory>

#include "Context.h"
#include "AST.h"

enum ExitCode
{
	EX_SUCCESS = 0,
	EX_ERROR   = -1,
};

class WLInterpreter
{
public:

	/*
		Construct an interpreter for the given input program
	*/
	WLInterpreter();
	
	/*
		Build an Abstract Syntax Tree from a given sequence of chars
	*/
	bool build(std::istream& program);
	
	/*
		Print the abstract syntax tree to the logging stream
	*/
	void print();
	
	/*
		Execute the given program
	*/
	ExitCode execute();
	
	/*
		Access logging stream
	*/
	void setLog(std::ostream& logstream) { m_log = &logstream; }
	std::ostream& log() { return *m_log; }

private:

	std::ostream* m_log;

	ASTNode m_syntaxTree;

	Context m_ctx;
};
