#include "../include/IDialogInput.h"
#include <string>
#include <map>
#include <stdexcept>

class MockInputHandler : public IDialogInput {
    std::string mockExpression;
    std::map<std::string, double> mockVariableValues;

public:
    MockInputHandler(const std::string& expression, const std::map<std::string, double>& variableValues)
        : mockExpression(expression), mockVariableValues(variableValues) {}

    std::string getExpression() const {
        return mockExpression;
    }

    double resolveVariable(const std::string& variableName) const override {
        auto it = mockVariableValues.find(variableName);
        if (it == mockVariableValues.end()) {
            throw std::runtime_error("Mock value for variable " + variableName + " not found.");
        }
        return it->second;
    }
};