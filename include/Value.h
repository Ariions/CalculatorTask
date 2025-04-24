#ifndef VALUE_H
#define VALUE_H

#include "Inode.h"

class Value : public Inode {
private:
    double value;

public:
    Value(double val);

    double calc() const override;
    std::string print() const override;
};

#endif // VALUE_H