/*
	Command Line Interface for WhileLang interpreter
*/

#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>

#include "wl/Interpreter.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
	Command Line Argument parsing functions
*/

namespace
{
	enum Option
	{
		NONE         = 0,
		HELP         = 1,
		PRINT_AST    = 2,
		PRINT_TOKENS = 4,
		
	};
	
	bool islegalFilePath(const char* path)
	{
		const char* cur = path;
		
		//Illegal character set
		const char filter[] = "*\"[]:;|=,";
		std::unordered_set<char> illegalChars(std::begin(filter), std::end(filter));
		
		//Foreach char
		while (*cur != 0)
		{
			//Verify if char is legal
			if (illegalChars.find(*cur) != illegalChars.end())
				return false;
			
			cur++;
		}
		
		return true;
	}
	
	void printHelp()
	{
		std::cout << "~~~WhileLang interpreter~~~\n";
		std::cout << "Arguments:\n";
		std::cout << "-help | -?       prints help options\n";
		std::cout << "-print-ast       prints the program Abstract Syntax Tree\n";
		std::cout << "-print-tokens    prints the program tokens\n";
		std::cout << "Usage:\n";
		std::cout << "wlc {[OPTIONS...]}{[FILE]|STDIN}\n";
		std::cout.flush();
	}

	//Parse command line arguments
	bool parseArgs(int argc, char** argv, std::string& filepath, uint32_t& opts)
	{
		opts = Option::NONE;
		
		//Option set
		std::unordered_map<std::string, Option> m_options = {
			{"-?",            Option::HELP         },
			{"-help",         Option::HELP         },
			{"-print-ast",    Option::PRINT_AST    },
			{"-print-tokens", Option::PRINT_TOKENS },
		};
		
		for (int i = 1; i < argc; i++)
		{
			const char* arg = argv[i];
			
			//Expect option
			if (arg[0] == '-')
			{				
				auto it = m_options.find(arg);
				
				//If option was found
				if (it != m_options.end())
				{
					opts |= it->second;
				}
				else
				{
					//otherwise unknown option
					std::cerr << "Unknown option:" << arg << std::endl;
					return false;
				}
			}
			else if (islegalFilePath(arg))
			{
				filepath = arg;
			}
			else
			{
				std::cerr << "Illegal file path given: " << arg << std::endl;
				return false;
			}
		}
		
		return true;
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(int argc, char** argv)
{
	/*
		Parse arguments
	*/
	
	std::string filePath;
	uint32_t opts = 0;
	
	if (!parseArgs(argc, argv, filePath, opts))
	{
		return -1;
	}
	
	//Print help options
	if (opts & Option::HELP)
	{
		printHelp();
		return 0;
	}
	
	//Current stream source - default stdin
	std::reference_wrapper<std::istream> stream(std::cin);
	//File stream source
	std::ifstream fileStream;
	
	//If a file was specified, set stream source to that file
	if (!filePath.empty())
	{
		//Open file
		fileStream.open(filePath);

		if (fileStream.fail())
		{
			std::cerr << "Unable to find file \"" << filePath << "\"";
			return -1;
		}

		stream = fileStream;
	}
	
	WLInterpreter i;
	
	//Just print the tokens
	if (opts & Option::PRINT_TOKENS)
	{
		Tokenizer tokens(stream.get());
		
		const size_t align = 30;
		
		//Print tokens
		//(LINE#:TOKNUM#)[TYPE] -> "SYMBOL"
		while (tokens.hasNext())
		{
			Token t = tokens.next();

			std::cout << std::setw(align) << std::left << (
				std::string()
				+ "(" + std::to_string(t.line) + ":" + std::to_string(t.toknum) + ")["
				+ Token::codeToString(t.code) + "]"
			);
			
			std::cout << "-> \"" << t.symbol << "\"";
			std::cout << std::endl;
		}
		
		return 0;
	}
	
	//Build AST
	if (!i.build(stream.get()))
	{
		return -1;
	}
	
	//Just print the AST
	if (opts & Option::PRINT_AST)
	{
		i.print();
		return 0;
	}
	
	if (stream.get().rdbuf() == std::cin.rdbuf())
	{
		//clear input before execution
		//prevents issues when std::cin was used to build the AST
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
	}
	
	//Execute AST
	if (auto err = i.execute())
	{
		std::cerr << "Failed with error: "<< err << std::endl;
		return err;
	}
	
	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
