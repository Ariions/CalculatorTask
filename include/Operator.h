#pragma once
#include "INode.h"
#include <string>
#include <functional>
#include <map>

class Operator : public INode {
    const std::string op;
    INode* left;
    INode* right;

    static const std::map<std::string, std::function<double(double, double)>> operations;

public:
    Operator(const std::string& op, INode* l, INode* r);
    ~Operator() override {
#ifndef TEST_BUILD
        delete left;
        delete right;
#endif
    }

    double calc() const override;
    std::string print() const override;
};