#pragma once
#include <string>
class Inode {
public:
    virtual ~Inode() = default;
    virtual double calc() const = 0;
    virtual std::string print() const = 0;
};