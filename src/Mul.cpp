#include "../include/Mul.h" // Adjust the path to match the actual location of Mul.h

Mul::Mul(Inode* l, Inode* r) : left(l), right(r) {}

Mul::~Mul() {}

double Mul::calc() const {
    return left->calc() * right->calc();
}

std::string Mul::print() const {
    return "(" + left->print() + " * " + right->print() + ")";
}