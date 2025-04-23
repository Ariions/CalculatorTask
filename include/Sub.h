#pragma once
#include "Inode.h"

class Sub : public Inode {
    Inode* left;
    Inode* right;
public:
    Sub(Inode* l, Inode* r);
    ~Sub();
    double calc() const override;
    std::string print() const override;
};