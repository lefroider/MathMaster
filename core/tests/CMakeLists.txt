
add_executable(core_test test_lexer.cpp)
target_link_libraries(core_test core GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main gtest_include)
add_test(NAME test1 COMMAND core_test)


