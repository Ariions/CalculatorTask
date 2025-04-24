#pragma once
#ifndef PARSER_H
#define PARSER_H

#include "Inode.h"
#include <string>
#include <map>
#include <sstream>

class Parser {
public:
    Inode* parse(const std::string& expression, std::map<std::string, double>& variables);

private:
    Inode* parseExpression(std::istringstream& stream, std::map<std::string, double>& variables);
    Inode* parseTerm(std::istringstream& stream, std::map<std::string, double>& variables);
    Inode* parseFactor(std::istringstream& stream, std::map<std::string, double>& variables);
};

#endif // PARSER_H