cmake_minimum_required(VERSION 3.14)
project(MalenaTest)

include(FetchContent)
FetchContent_Declare(
        malena
        GIT_REPOSITORY https://github.com/daversmith/Malena.git
        GIT_TAG v0.2.3
)
FetchContent_MakeAvailable(malena)

add_executable(${PROJECT_NAME}
        main.cpp
        MineSweeper/MineSweeper.cpp
        MineSweeper/MineSweeper.h
        MineSweeper/TextureSlicerDemo/TextureSlicerDemo.cpp
        MineSweeper/TextureSlicerDemo/TextureSlicerDemo.h
        MineSweeper/TextureSlicerDemo/Bomb.cpp
        MineSweeper/TextureSlicerDemo/Bomb.h
        backtracking/Node.cpp
        backtracking/Node.h
        backtracking/Model.cpp
        backtracking/Model.h
        backtracking/BackTracking.cpp
        backtracking/BackTracking.h
        randy/NQueens.cpp
        randy/NQueens.h
)

target_link_libraries(${PROJECT_NAME} PRIVATE Malena::Malena)