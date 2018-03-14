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

libwl_inc = include_directories('libwl/include')

libwl = static_library('wl',
	sources : files(
		'libwl/include/wl/Tokenizer.h',
		'libwl/include/wl/Context.h',
		'libwl/include/wl/Evaluator.h',
		'libwl/include/wl/Statement.h',
		'libwl/include/wl/Interpreter.h',
		'libwl/src/SyntaxError.h',
		'libwl/src/CharTypes.h',
		'libwl/src/Context.cpp',
		'libwl/src/Interpreter.cpp',
		'libwl/src/Tokenizer.cpp',
		'libwl/src/TokenEnum.cpp'
	),
	include_directories : libwl_inc
)

executable('wlc',
	sources : files(
		'wlc/main.cpp'
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