#pragma once
#include "Inode.h"

class Div : public Inode {
    Inode* left;
    Inode* right;
public:
    Div(Inode* l, Inode* r);
    ~Div();
    double calc() const override;
    std::string print() const override;
};