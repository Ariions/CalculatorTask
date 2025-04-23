#pragma once
#include <string>
#include "Inode.h"
#include <unordered_map>

class Parser {
public:
    static Inode* parse(const std::string& expression);
};