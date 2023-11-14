cmake_minimum_required(VERSION 3.14)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(NAME_EXECUTABLE "Chess")
set(NAME_TEST "ChessTest")
set(PATHS include/)

project(${NAME_EXECUTABLE})

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(${NAME_EXECUTABLE} ./src/main.cpp)
add_library(ChessFigure ./src/ChessFigure.cpp)
add_library(FigureMoveValidation ./src/FigureMoveValidation.cpp)
add_library(BishopMoveValidation ./src/BishopMoveValidation.cpp)
add_library(PawnMoveValidation ./src/PawnMoveValidation.cpp)
add_library(RookMoveValidation ./src/RookMoveValidation.cpp)
add_library(KnightMoveValidation ./src/KnightMoveValidation.cpp)
add_library(QueenMoveValidation ./src/QueenMoveValidation.cpp)
add_library(KingMoveValidation ./src/KingMoveValidation.cpp)
add_executable(${NAME_TEST} ./test/test.cpp)

target_include_directories(ChessFigure
    PRIVATE "${PATHS}"
)
target_include_directories(FigureMoveValidation
    PRIVATE "${PATHS}"
)
target_include_directories(BishopMoveValidation
    PRIVATE "${PATHS}"
)
target_include_directories(PawnMoveValidation
    PRIVATE "${PATHS}"
)
target_include_directories(RookMoveValidation
    PRIVATE "${PATHS}"
)
target_include_directories(KnightMoveValidation
    PRIVATE "${PATHS}"
)
target_include_directories(QueenMoveValidation
    PRIVATE "${PATHS}"
)
target_include_directories(KingMoveValidation
    PRIVATE "${PATHS}"
)

target_include_directories(${NAME_EXECUTABLE}
    PRIVATE "${PATHS}"
)

target_link_libraries(${NAME_EXECUTABLE} PRIVATE
    ChessFigure FigureMoveValidation BishopMoveValidation PawnMoveValidation RookMoveValidation KnightMoveValidation QueenMoveValidation KingMoveValidation
)

target_include_directories(${NAME_TEST}
    PRIVATE "${PATHS}"
)

target_link_libraries(${NAME_TEST} 
    ChessFigure FigureMoveValidation BishopMoveValidation PawnMoveValidation RookMoveValidation KnightMoveValidation QueenMoveValidation KingMoveValidation
)

target_link_libraries(
  ${NAME_TEST}
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(${NAME_TEST})