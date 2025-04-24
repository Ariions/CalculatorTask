#ifndef VALUE_H
#define VALUE_H

#include "INode.h"

class Value : public INode {
private:
    double value;

public:
    Value(double val);

    double calc() const override;
    std::string print() const override;
};

#endif // VALUE_H