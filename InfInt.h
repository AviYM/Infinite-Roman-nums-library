//
// Created by avi on 11/8/18.
//

#ifndef EX1_INFINT_H
#define EX1_INFINT_H

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <regex>
using namespace std;

class InfInt {

private:
    // members
    vector<bool> digits;
    bool sign;

public:
    // constructors
    InfInt();
    InfInt(string cobigNum);
    InfInt(long num);
    InfInt(vector<bool> num, bool sign);
    InfInt(InfInt const& numToCopy);
    ~InfInt();
    explicit operator int() const;

    // binary operators
    InfInt operator++();
    InfInt operator++(int);
    InfInt operator+=(InfInt other);
    InfInt operator+=(int other);
    InfInt operator+(InfInt num);
    InfInt operator-(InfInt other);
    InfInt operator-(); // unary operator
    InfInt operator-=(InfInt other);
    InfInt operator--();
    InfInt operator--(int);
    InfInt operator*(InfInt other);
    InfInt operator/(InfInt other);
    InfInt operator%(InfInt other);

    // boolian operators
    bool operator==(InfInt other);
    bool operator<=(InfInt other);
    bool operator>=(InfInt other);
    bool operator<(InfInt other);
    bool operator>(InfInt other);

    // bitwise operators
    InfInt operator&(InfInt other);
    InfInt operator|(InfInt other);
    InfInt operator^(InfInt other);
    InfInt operator&=(InfInt other);
    InfInt operator<<(int mult);
    InfInt operator>>(int mult);
    InfInt operator>>=(int mult);

    //iostream operators
    friend ostream& operator<<(ostream& os, const InfInt& num);
    friend istream& operator>>(istream& is, InfInt& num);

private:
    typedef bool (*bitwiseOprator) (bool b1, bool b2);
    InfInt operatBitwiseOperators(InfInt num1, InfInt num2, bitwiseOprator func);
    InfInt getDivisionOrModulo(InfInt other, bool flag);
};

#endif //EX1_INFINT_H
#pragma once
