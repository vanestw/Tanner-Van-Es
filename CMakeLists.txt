# CMakeLists.txt

cmake_minimum_required(VERSION 3.27)
project(main)

# Compiler settings
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wfloat-equal -Wundef -Wcast-align -Wwrite-strings -Wlogical-op -Wmissing-declarations -Wredundant-decls -Wshadow -Woverloaded-virtual")

# Path settings
set(SRC_PATH src)
#set(OBJ_PATH ../obj)
set(BIN_PATH ../bin)

# Add main target
file(GLOB MAIN_SOURCES "${SRC_PATH}/*.cpp")
add_executable(main ${MAIN_SOURCES})
set_target_properties(main PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${BIN_PATH}"
    ARCHIVE_OUTPUT_DIRECTORY "${OBJ_PATH}"
    LIBRARY_OUTPUT_DIRECTORY "${OBJ_PATH}"
)
