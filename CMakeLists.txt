# CMakeLists.txt

cmake_minimum_required(VERSION 3.12)
project(main)

# Compiler settings
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wfloat-equal -Wundef -Wcast-align -Wwrite-strings -Wlogical-op -Wmissing-declarations -Wredundant-decls -Wshadow -Woverloaded-virtual")

# Path settings
set(BIN_PATH ../bin)
set(OBJ_PATH ../obj)
set(SRC_PATH src)

# Function to add an executable target
function(add_target EXEC_NAME SOURCES_DIR)
    file(GLOB EXECUTABLE_SOURCES "${SOURCES_DIR}/*.cpp")
    add_executable(${EXEC_NAME} ${EXECUTABLE_SOURCES})
    set_target_properties(${EXEC_NAME} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${BIN_PATH}"
    )
    set_target_properties(${EXEC_NAME} PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY "${OBJ_PATH}"
        LIBRARY_OUTPUT_DIRECTORY "${OBJ_PATH}"
    )
endfunction()

# Add main target
set(MAIN_SRC_DIR ${SRC_PATH})
add_target(main ${MAIN_SRC_DIR})
