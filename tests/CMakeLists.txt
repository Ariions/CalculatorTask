# Enable testing
enable_testing()

# Add GoogleTest (either via FetchContent or if it's already installed on the system)
include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

# Gather test source files
file(GLOB TEST_SOURCES "*.cpp")

# Add test executable
add_executable(UnitTests ${TEST_SOURCES})

# Include main include directory for headers
target_include_directories(UnitTests PRIVATE ${PROJECT_SOURCE_DIR}/include)

# Link test executable with GTest and your project’s main library (if applicable)
target_link_libraries(UnitTests gtest_main)

# Optionally link other project source files if not already in a library
target_sources(UnitTests PRIVATE
    ${PROJECT_SOURCE_DIR}/src/Value.cpp
    ${PROJECT_SOURCE_DIR}/src/Sum.cpp
    ${PROJECT_SOURCE_DIR}/src/Sub.cpp
    ${PROJECT_SOURCE_DIR}/src/Mul.cpp
    ${PROJECT_SOURCE_DIR}/src/Div.cpp
    ${PROJECT_SOURCE_DIR}/src/Parser.cpp
    ${PROJECT_SOURCE_DIR}/src/VariableResolver.cpp
)

# Register the test with CTest
include(GoogleTest)
gtest_discover_tests(UnitTests)