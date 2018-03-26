/*
	Entry point
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
	
	std::ifstream s(argv[1]);

	if (s.fail())
	{
		std::cerr << "Unable to find file: " << argv[1] << std::endl;
		return -2;
	}

	WLInterpreter i(s);

	if (auto err = i.execute())
	{
		std::cerr << "Failed with error: "<< err << std::endl;
		return -1;
	}

	return 0;

	//////////////////////////////////////////////////

	std::cout << "type string:" << std::endl;
	
	while (std::cin)
	{
		std::stringstream ss;
		std::string lnbuf;
		
		getline(std::cin, lnbuf);
		ss << lnbuf;
		
		Tokenizer tokenizer(ss);
		
		while (tokenizer.hasNext())
		{	
			Token t = tokenizer.next();

			std::cout
				<< "["
				<< Token::codeToString(t.code)
				<< "]\t-> \""
				<< t.symbol
				<< "\""
				<< std::endl;
		}
	}

	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
