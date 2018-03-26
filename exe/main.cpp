/*
	Command Line Interface for WhileLang interpreter
*/

#include <iostream>
#include <sstream>
#include <fstream>

#include "wl/Interpreter.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(int argc, char** argv)
{
	if (argc <= 1)
	{
		std::cerr << "Incorrect number of arguments, expected: [OPTIONS...] [FILE]." << std::endl;
		return -1;
	}
	
	WLInterpreter i;
	
	std::ifstream s(argv[1]);

	if (s.fail())
	{
		std::cerr << "Unable to find file: " << argv[1] << std::endl;
		return -2;
	}

	//build AST
	if (i.build(s))
	{
		//execute AST
		if (auto err = i.execute())
		{
			std::cerr << "Failed with error: "<< err << std::endl;
			return err;
		}
		
		return 0;
	}

	return -1;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
