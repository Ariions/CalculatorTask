#pragma once
#include "Inode.h"

class Sum : public Inode {
    Inode* left;
    Inode* right;
public:
    Sum(Inode* l, Inode* r);
    ~Sum();
    double calc() const override;
    std::string print() const override;
};