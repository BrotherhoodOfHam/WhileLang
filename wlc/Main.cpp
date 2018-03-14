/*
	Entry point
*/

#include <iostream>
#include <sstream>

#include "Tokenizer.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(int argc, char** argv)
{
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
