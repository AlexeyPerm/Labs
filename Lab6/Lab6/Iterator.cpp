#include "Iterator.h"

Iterator& Iterator::operator++() {
    ++current;
    return *this;
}

Iterator Iterator::operator++(int) {
    Iterator tmp(current);
    ++current;
    return tmp;
}

Iterator& Iterator::operator--() {
    --current;
    return *this;
}

Iterator Iterator::operator--(int) {
    Iterator tmp(current);
    --current;
    return tmp;
}

Iterator& Iterator::operator-=(const int n) {
    current -= n;
    return *this;
}
Iterator Iterator::operator-(const int n) {
    current -= n;
    return *this;
}