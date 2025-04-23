#include "../include/Sum.h" // Adjust the path to match the actual location of Sum.h

Sum::Sum(Inode* l, Inode* r) : left(l), right(r) {}

Sum::~Sum() {}

double Sum::calc() const {
    return left->calc() + right->calc();
}

std::string Sum::print() const {
    return "(" + left->print() + " + " + right->print() + ")";
}