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

# Add unit tests
file(GLOB UNIT_TEST_SOURCES "unit/*.cpp") # Automatically include all .cpp files in the unit folder
add_executable(UnitTests ${UNIT_TEST_SOURCES}
    ${PROJECT_SOURCE_DIR}/src/Operator.cpp
    ${PROJECT_SOURCE_DIR}/src/Value.cpp
    ${PROJECT_SOURCE_DIR}/src/Parser.cpp
    ${PROJECT_SOURCE_DIR}/src/VariableResolver.cpp
    ${PROJECT_SOURCE_DIR}/src/ExpretionResolver.cpp
)
target_include_directories(UnitTests PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(UnitTests gtest gtest_main)

# Define TEST_BUILD macro for UnitTests
target_compile_definitions(UnitTests PRIVATE ON_STACK)

# Register unit tests with CTest
include(GoogleTest)
gtest_discover_tests(UnitTests
    TEST_PREFIX "Unit."
    PROPERTIES LABELS "unit"
)

# Add integration tests
file(GLOB INTEGRATION_TEST_SOURCES "integration/*.cpp") # Automatically include all .cpp files in the integration folder
add_executable(IntegrationTests ${INTEGRATION_TEST_SOURCES}
    ${PROJECT_SOURCE_DIR}/src/ExpretionResolver.cpp
    ${PROJECT_SOURCE_DIR}/src/Operator.cpp
    ${PROJECT_SOURCE_DIR}/src/Value.cpp
    ${PROJECT_SOURCE_DIR}/src/Parser.cpp
    ${PROJECT_SOURCE_DIR}/src/VariableResolver.cpp
)
target_include_directories(IntegrationTests PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(IntegrationTests gtest gtest_main)

# Register integration tests with CTest
gtest_discover_tests(IntegrationTests
    TEST_PREFIX "Integration."
    PROPERTIES LABELS "integration"
)