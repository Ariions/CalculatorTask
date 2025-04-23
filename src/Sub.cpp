#include "../include/Sub.h" // Adjust the path to match the actual location of Sub.h

Sub::Sub(Inode* l, Inode* r) : left(l), right(r) {}

Sub::~Sub() {}

double Sub::calc() const {
    return left->calc() - right->calc();
}

std::string Sub::print() const {
    return "(" + left->print() + " - " + right->print() + ")";
}