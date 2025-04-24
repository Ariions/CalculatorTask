#pragma once
#ifndef PARSER_H
#define PARSER_H

#include "INode.h"
#include <string>
#include <map>
#include <sstream>

class Parser {
public:
    INode* parse(const std::string& expression, std::map<std::string, double>& variables);
    INode* parseExpression(std::istringstream& stream, std::map<std::string, double>& variables);
    INode* parseTerm(std::istringstream& stream, std::map<std::string, double>& variables);
    INode* parseFactor(std::istringstream& stream, std::map<std::string, double>& variables);
};

#endif // PARSER_H