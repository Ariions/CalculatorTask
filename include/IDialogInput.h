#pragma once
#include <string>
#include <map>

class IDialogInput {
public:
    virtual ~IDialogInput() = default;
    virtual double resolveVariable(const std::string& variableName) const = 0;
};