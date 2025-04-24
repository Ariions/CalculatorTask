#pragma once
#include "Inode.h"
#include <string>
#include <functional>
#include <map>

class Operator : public Inode {
    const std::string op;
    Inode* left;
    Inode* right;

    static const std::map<std::string, std::function<double(double, double)>> operations;

public:
    Operator(const std::string& op, Inode* l, Inode* r);
    ~Operator() override = default;

    double calc() const override;
    std::string print() const override;
};