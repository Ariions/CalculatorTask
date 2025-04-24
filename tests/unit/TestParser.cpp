#include <gtest/gtest.h>
#include "../../include/Parser.h"
#include "../../include/Value.h"
#include "../../include/VariableResolver.h"

TEST(ParserClass, ParseSimpleValue) {
    std::istringstream stream("42");
    std::map<std::string, double> variables;
    Parser parser;
    Inode* node = parser.parseFactor(stream, variables);
    EXPECT_DOUBLE_EQ(node->calc(), 42.0);
    delete node;
}

TEST(ParserClass, ParseVariable) {
    std::istringstream stream("x");
    std::map<std::string, double> variables = {{"x", 5.0}};
    Parser parser;
    Inode* node = parser.parseFactor(stream, variables);
    EXPECT_DOUBLE_EQ(node->calc(), 5.0);
    delete node;
}

TEST(ParserClass, ParseNegativeNumber) {
    std::istringstream stream("-42");
    std::map<std::string, double> variables;
    Parser parser;
    Inode* node = parser.parseFactor(stream, variables);
    EXPECT_DOUBLE_EQ(node->calc(), -42.0);
    delete node;
}

TEST(ParserClass, ParseComplexExpression) {
    std::istringstream stream("(3 + 4) * 2");
    std::map<std::string, double> variables;
    Parser parser;
    Inode* node = parser.parseExpression(stream, variables);
    EXPECT_DOUBLE_EQ(node->calc(), 14.0);
    delete node;
}