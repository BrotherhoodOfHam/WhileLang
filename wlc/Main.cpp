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
	std::ifstream s("../samples/a.w");

	if (s.fail())
	{
		std::cerr << "unable to find file." << std::endl;
		return -2;
	}

	WLInterpreter i(s);

	if (auto err = i.execute())
	{
		std::cout << err << std::endl;
		std::cin.get();
		return -1;
	}

	std::cin.get();
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
