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

subdir('libwl')

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