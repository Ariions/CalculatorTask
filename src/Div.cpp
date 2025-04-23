#include "../include/Div.h" // Adjust the path to match the actual location of Div.h
#include <stdexcept> // For handling division by zero exceptions

Div::Div(Inode* l, Inode* r) : left(l), right(r) {}

Div::~Div() {}

double Div::calc() const {
    if (right->calc() == 0) {
        throw std::runtime_error("Division by zero");
    }
    return left->calc() / right->calc();
}

std::string Div::print() const {
    return "(" + left->print() + " / " + right->print() + ")";
}