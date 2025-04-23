#pragma once
#include "Inode.h"

class Mul : public Inode {
    Inode* left;
    Inode* right;
public:
    Mul(Inode* l, Inode* r);
    ~Mul();
    double calc() const override;
    std::string print() const override;
};