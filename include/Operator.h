#pragma once
#include "Inode.h"

class Operator : public Inode {
    const std::string op;
    Inode* left;
    Inode* right;
public:
    Operator(const std::string& op, Inode* l, Inode* r);
    ~Operator();
    double calc() const override;
    std::string print() const override;
};