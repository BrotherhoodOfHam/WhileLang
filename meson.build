########################################################################
#	WhileLang project
########################################################################

project('WhileLang', 'cpp')

#
#	Setup gtest
#
gtest = dependency('gtest', main : true, required : false)

if not gtest.found()
	gtest = subproject('gtest').get_variable('gtest_dep')
endif

########################################################################
#	Interpreter
########################################################################

libwl_inc = include_directories('include')

#
#	LibWL
#
libwl = static_library('wl',
	sources : files(
		'include/wl/Tokenizer.h',
		'include/wl/AST.h',
		'include/wl/Context.h',
		'include/wl/Interpreter.h',
		'include/wl/SyntaxError.h',
		'src/CharTypes.h',
		'src/Context.cpp',
		'src/Interpreter.cpp',
		'src/Tokenizer.cpp',
		'src/TokenEnum.cpp',
		'src/AST/ProgramDeclaration.h',
		'src/AST/Command.h',
		'src/AST/CommandList.h',
		'src/AST/ArithmeticExpression.h',
		'src/AST/BooleanExpression.h',
		'src/AST/AssignmentStatement.h',
		'src/AST/BinaryOperator.h',
		'src/AST/IfElseStatement.h',
		'src/AST/WhileStatement.h',
		'src/AST/IOReadCommand.h',
		'src/AST/IOWriteCommand.h',
		'src/AST/Literal.h',
		'src/AST/Variable.h',
		'src/AST/VariableDeclaration.h',
		'src/AST/VariableDeclarationList.h',
	),
	include_directories : libwl_inc
)

#
#	WL executable
#
executable('wlc',
	sources : files(
		'exe/main.cpp'
	),
	link_with : libwl,
	include_directories : libwl_inc
)

########################################################################
#	Tests
########################################################################

wltest = executable('wltest',
	sources : files(
		'tests/test_tokenizer.cpp',
		'tests/test.cpp'
	),
	link_with : libwl,
	include_directories : libwl_inc,
	dependencies : gtest
)

test('test', wltest)

########################################################################