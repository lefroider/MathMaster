
set(SOURCES
    interpreter.cpp
    parser.cpp
    lexer.cpp
    astOperand.cpp
    astOperator.cpp
)

add_library(core STATIC ${SOURCES})
target_link_libraries(core PUBLIC core_includes)


