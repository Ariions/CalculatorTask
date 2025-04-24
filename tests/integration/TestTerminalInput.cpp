#include <gtest/gtest.h>
#include "../../src/TerminalInput.cpp"
#include <sstream>
#include <string>

TEST(TerminalInputClass, GetExpression) {
    // Simulate user input
    std::istringstream input("3 + 4\n");
    std::cin.rdbuf(input.rdbuf()); // Redirect std::cin to use the simulated input

    TerminalInput terminalInput;
    std::string expression = terminalInput.getExpression();

    EXPECT_EQ(expression, "3 + 4");
}

TEST(TerminalInputClass, ResolveVariable) {
    // Simulate user input
    std::istringstream input("42\n");
    std::cin.rdbuf(input.rdbuf()); // Redirect std::cin to use the simulated input

    TerminalInput terminalInput;
    double value = terminalInput.resolveVariable("x");

    EXPECT_DOUBLE_EQ(value, 42.0);
}

TEST(TerminalInputClass, InvalidVariableInput) {
    // Simulate invalid user input
    std::istringstream input("invalid\n");
    std::cin.rdbuf(input.rdbuf()); // Redirect std::cin to use the simulated input

    TerminalInput terminalInput;
    EXPECT_THROW(terminalInput.resolveVariable("x"), std::runtime_error); 
}