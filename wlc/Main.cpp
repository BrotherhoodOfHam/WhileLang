/*
	Entry point
*/

#include <iostream>
#include <sstream>

#include "wl/Interpreter.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(int argc, char** argv)
{
	const char str[] = "program\n"
		"var x : nat;\n"
		"begin\n"
		"end\n";

	std::stringstream s;
	s << str;

	WLInterpreter i(s);

	if (auto err = i.execute())
	{
		std::cout << err << std::endl;
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
