#pragma once
#include "Inode.h"

class Value : public Inode {
protected:
    double value;
public:
    Value(double val);
    double calc() const override;
    std::string print() const override;
};