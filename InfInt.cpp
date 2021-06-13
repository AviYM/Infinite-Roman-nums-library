//
// Created by avi on 11/8/18.
//

#include "InfInt.h"

vector<bool> twosComplement(vector<bool> posRepresentation) {
    vector<bool> negRepresentation;
    for (bool b : posRepresentation) {
        negRepresentation.push_back(b ? 0 : 1);
    }
    for (size_t i = 0; i < negRepresentation.size(); ++i) {
        if (negRepresentation[i] == 0) {
            negRepresentation[i] = 1;
            break;
        }
        else {
            negRepresentation[i] = 0;

        }
    }
    return negRepresentation;
}

int charToInt(char c) {
    return c - '0';
}

char intToChar(int i) {
    return i + '0';
}

void addZeros(vector<bool>& num, long numOfZeros) {
    for (int j = 0; j < numOfZeros; ++j) {
        num.push_back(0);
    }
}

void removeMsbZeros(vector<bool>& num) {
    for (int j = num.size() - 1; j > 0; --j) {
        if (num[j - 1]) {
            break;
        }
        num.pop_back();
    }
}

vector<bool> decimalToBinary(string& num) {
    vector<bool> binaryNum;
    int startRun = 0;
    // Skips zeros at the beginning of the number. For example, "00"123.
    while (num[startRun] == '0' && startRun < num.length() - 1) {
        startRun++;
    }
    if (num[startRun] == '0') {
        binaryNum.push_back(0);
        return binaryNum;
    }
    while (num[startRun] != '0') {
        int prevRemainder = 0;
        for (int i = startRun; i < num.length(); ++i) {
            int digit = charToInt(num[i]);
            digit += (prevRemainder * 10);
            prevRemainder = digit % 2;
            num[i] = intToChar(digit / 2);
            if (i == startRun && num[i] == '0' && startRun != (num.length() - 1)) {
                startRun++;
            }
        }
        binaryNum.push_back(prevRemainder);
        //cout << prevRemainder;
    }
    addZeros(binaryNum, 1);
    return binaryNum;
}

string add(string num1, string num2) {
    string ret = "";
    int size = num1.size() - num2.size();
    size = abs(size);
    string zeros = "";
    if (num1.size() > num2.size()) {
        for (int i = 0; i < size; ++i) {
            zeros += "0";
        }
        num2 = zeros + num2;
    }
    if (num2.size() > num1.size()) {
        for (int i = 0; i < size; ++i) {
            zeros += "0";
        }
        num1 = zeros + num1;
    }
    int remainder = 0;
    int temp = 0;
    for (int i = num1.size() - 1; i >= 0; i--) {
        temp = charToInt(num1[i]) + charToInt(num2[i]) + remainder;
        ret = intToChar(temp % 10) + ret;
        remainder = temp / 10;
    }
    if (remainder) {
        ret = intToChar(remainder) + ret;
    }
    return ret;
}

string binaryToDecimal(vector<bool> binaryNum, bool sign) {
    string ret = "0";
    string current = "0";
    for (size_t i = binaryNum.size(); i > 0; --i) {
        current = to_string(binaryNum[i - 1]);
        string mult = add(ret, ret);
        ret = add(mult, current);
    }
    if (sign) {
        ret = "-" + ret;
    }
    return ret;
}

string vecBinaryToStrBinary(vector<bool> binaryNum, bool sign) {
    string ret = "";

    if (sign) {
        binaryNum = twosComplement(binaryNum);
    }
    for (size_t i = binaryNum.size(); i > 0; --i) {
        ret += to_string(binaryNum[i - 1]);
    }
    return ret;
}

void comparesSizeOfTwoBinaryNums(vector<bool>& num1, vector<bool>& num2) {
    long difference = num1.size() - num2.size();
    difference = abs(difference);
    if (num1.size() > num2.size()) {
        addZeros(num2, difference);
    }
    if (num2.size() > num1.size()) {
        addZeros(num1, difference);
    }
}

bool getTheSignOfNumber(string& num) {
    if (num[0] == '-') {
        num[0] = '0';
        return true;
    }
    else {
        return false;
    }
}

bool isRomanNumerals(string& num) {
    if (num.size() == 1 && num[0] >= '0' && num[0] <= '9') {
        return false;
    }
    if (num[1] >= '0' && num[1] <= '9') {
        return false;
    }
    return true;
}

int letterToInt(char ltr) {
    switch (ltr) {
    case 'I': case 'i': return 1;
    case 'V': case 'v': return 5;
    case 'X': case 'x': return 10;
    case 'L': case 'l': return 50;
    case 'C': case 'c': return 100;
    case 'D': case 'd': return 500;
    case 'M': case 'm': return 1000;
    default:
        return 0;
    }
}

InfInt romanToDecimal(string& num) {
    InfInt res = 0;
    long i = 0;
    num[0] == '0' ? ++i : i;

    for (; i < num.size(); i++) {
        long coefficient = 1;  
        while (num[i] == '_') {
            coefficient *= 1000;
            ++i;
        }

        char ltr1 = num[i], ltr2;
        i < num.size() - 1 ? ltr2 = num[i + 1] : ltr2 = 'I';
        long ltoi1 = coefficient * letterToInt(ltr1);
        int ltoi2 = letterToInt(ltr2);
        ltoi1 >= ltoi2 ? res += ltoi1 : res -= ltoi1;
    }

    return res;
}

string unityDigitToLetter(char d) {
    switch (d) {
    case '1': return "I";
    case '2': return "II";
    case '3': return "III";
    case '4': return "IV";
    case '5': return "V";
    case '6': return "VI";
    case '7': return "VII";
    case '8': return "VIII";
    case '9': return "IX";
    default:
        return "";
    }
}

string tensDigitToLetter(char d) {
    switch (d) {
    case '1': return "X";
    case '2': return "XX";
    case '3': return "XXX";
    case '4': return "XL";
    case '5': return "L";
    case '6': return "LX";
    case '7': return "LXX";
    case '8': return "LXXX";
    case '9': return "XC";
    default:
        return "";
    }
}

string hundredDigitToLetter(char d) {
    switch (d) {
    case '1': return "C";
    case '2': return "CC";
    case '3': return "CCC";
    case '4': return "CD";
    case '5': return "D";
    case '6': return "DC";
    case '7': return "DCC";
    case '8': return "DCCC";
    case '9': return "CM";
    default:
        return "";
    }
}

string addUs(string digit, string delimiter) {
    if (digit == "") return "";

    string res = "";
    for (int i = 0; i < digit.size(); i++) {
        res += delimiter;
        res += digit[i];    
    }

    return res;
}

string intToLetter(long length, char ltr) {
    string res = "";
    
    long new_l = length;
    while (new_l > 3) {
        res += "_";
        length = new_l;
        new_l = length - 3;
    }

    switch (new_l) {
    case 1: res = addUs(unityDigitToLetter(ltr), res); 
        break;
    case 2: res = addUs(tensDigitToLetter(ltr), res); 
        break;
    case 3: res = addUs(hundredDigitToLetter(ltr), res); 
        break;
    default:
        break;
    }

    res = std::regex_replace(res, std::regex("_I"), "M");
    return res;
}

string decimalToRoman(string& num) {
    string res = "";
    long num_size = num.size();

    for (long i = 0; i < num_size; i++) {
        res += intToLetter(num_size - i, num[i]);
    }

    return res;
}

InfInt::InfInt() {
    this->digits = { 0 };
    this->sign = false;
}

InfInt::InfInt(string bigNum) {
    this->sign = getTheSignOfNumber(bigNum);
    if (isRomanNumerals(bigNum)) {
        this->digits = romanToDecimal(bigNum).digits;
        return;
    }
    this->digits = decimalToBinary(bigNum);
    // if this->digits.size() == 1 it means which one of the digits = 0,
    // and 0 will be treated as positive number.
    if (this->digits.size() == 1) {
        this->sign = 0;
    }
}

InfInt::InfInt(long num) {
    string numAsStr = to_string(num);
    this->sign = getTheSignOfNumber(numAsStr);
    this->digits = decimalToBinary(numAsStr);
}

InfInt::InfInt(vector<bool> num, bool sign) {
    this->digits = num;
    this->sign = sign;
}

InfInt::InfInt(InfInt const& numToCopy) {
    this->digits = numToCopy.digits;
    this->sign = numToCopy.sign;
}

InfInt::~InfInt() {}

InfInt InfInt::operator++() { // ++x
    return *this += InfInt(1);
}

InfInt InfInt::operator++(int) { //x++
    InfInt ret(*this);
    *this += InfInt(1);
    return ret;
}

InfInt InfInt::operator+=(InfInt other) {
    return *this = *this + other;
}

InfInt InfInt::operator+=(int other) {
    return *this += InfInt(other);
}

InfInt InfInt::operator+(InfInt other) {
    comparesSizeOfTwoBinaryNums(this->digits, other.digits);
    addZeros(this->digits, 1);
    addZeros(other.digits, 1);
    vector<bool> num1;
    vector<bool> num2;
    vector<bool> sum;
    if (this->sign) {
        num1 = twosComplement(this->digits);
    }
    else {
        num1 = this->digits;
    }
    if (other.sign) {
        num2 = twosComplement(other.digits);
    }
    else {
        num2 = other.digits;
    }
    int remainder = 0;
    for (size_t i = 0; i < num1.size(); ++i) {
        sum.push_back((remainder + num1[i] + num2[i]) % 2);
        remainder = (remainder + num1[i] + num2[i]) / 2;
    }
    bool sign = sum.back();
    if (sign) {
        sum = twosComplement(sum);
    }
    removeMsbZeros(this->digits);
    removeMsbZeros(other.digits);
    InfInt ret(sum, sign);
    return ret;
}

InfInt InfInt::operator-() {
    InfInt negative(this->digits, !this->sign);
    return negative;
}

InfInt InfInt::operator-(InfInt other) {
    return *this + (-other);
}

InfInt InfInt::operator-=(InfInt other) {
    return *this = *this - other;
}

InfInt InfInt::operator--() { // --x
    return *this -= InfInt(1);
}

InfInt InfInt::operator--(int) { //x--
    InfInt ret(*this);
    *this -= InfInt(1);
    return ret;
}

InfInt InfInt::operator*(InfInt other) {
    InfInt result(0);
    bool sign = 0;
    for (size_t i = 0; i < this->digits.size(); ++i) {
        if (this->digits[i]) {
            vector<bool> current;
            addZeros(current, i);
            for (bool b : other.digits) {
                current.push_back(b);
            }
            result += InfInt(current, 0);
        }
    }
    removeMsbZeros(this->digits);
    removeMsbZeros(other.digits);
    // - * + = - ; + * - = - ; X.digits.size > 1 <-> number.digits != 0 (0 * - = "+")
    if (this->sign ^ other.sign && this->digits.size() > 1 && other.digits.size() > 1) {
        sign = 1;
    }
    InfInt ret(result.digits, sign);
    return ret;
}

InfInt InfInt::getDivisionOrModulo(InfInt other, bool flag) {
    InfInt posOther(other.digits, false);
    if (other == InfInt(0)) {
        throw "Cannot divide by zero";
    }
    InfInt q, r;
    addZeros(q.digits, this->digits.size());
    addZeros(r.digits, this->digits.size());
    size_t len = this->digits.size();
    for (size_t i = len; i > 0; --i)
    {
        r = r * 2;
        r.digits[0] = this->digits[i - 1];
        if (r >= posOther)
        {
            r -= posOther;
            q.digits[i - 1] = 1;
        }
    }
    if (!flag) {
        InfInt ret(q.digits, sign);
        return ret;
    }
    else {
        InfInt ret(r.digits, sign);
        return ret;
    }
}

InfInt InfInt::operator/(InfInt other) {
    InfInt q(this->getDivisionOrModulo(other, 0));
    bool sign = 0;
    if (this->sign ^ other.sign && this->digits.size() > 1) {
        sign = 1;
    }
    InfInt ret(q.digits, sign);
    return ret;
}

InfInt InfInt::operator%(InfInt other) {
    InfInt r(this->getDivisionOrModulo(other, 1));
    bool sign = 0;
    if (this->sign && this->digits.size() > 1) {
        sign = 1;
    }
    InfInt ret(r.digits, sign);
    return ret;
}

bool InfInt::operator==(InfInt other) {
    removeMsbZeros(this->digits);
    removeMsbZeros(other.digits);
    if (this->sign == other.sign) {
        if (this->digits == other.digits) {
            return true;
        }
    }
    return false;
}

bool InfInt::operator>(InfInt other) {
    // + > -
    if (!this->sign && other.sign) {
        return true;
    }
    // - !> +
    if (this->sign && !other.sign) {
        return false;
    }
    comparesSizeOfTwoBinaryNums(this->digits, other.digits);
    // in case + > + || - > -
    for (size_t i = this->digits.size(); i > 0; --i) {
        if (this->digits[i - 1] > other.digits[i - 1]) {
            // this > other <-> -other > -this
            if (this->sign && other.sign) {
                return false;
            }
            return true;
        }
        if (other.digits[i - 1] > this->digits[i - 1]) {
            // other > this <-> -this > -other
            if (this->sign && other.sign) {
                return true;
            }
            return false;
        }
    }
    // this == other
    return false;
}

bool InfInt::operator>=(InfInt other) {
    if (*this > other || *this == other) {
        return true;
    }
    return false;
}

bool InfInt::operator<(InfInt other) {
    bool ret = *this >= other;
    return !ret;
}

bool InfInt::operator<=(InfInt other) {
    if (*this < other || *this == other) {
        return true;
    }
    return false;
}

InfInt InfInt::operatBitwiseOperators(InfInt num1, InfInt num2, bitwiseOprator func) {
    comparesSizeOfTwoBinaryNums(num1.digits, num2.digits);
    vector<bool> n1;
    vector<bool> n2;
    vector<bool> result;
    if (num1.sign) {
        n1 = twosComplement(num1.digits);
    }
    else {
        n1 = num1.digits;
    }
    if (num2.sign) {
        n2 = twosComplement(num2.digits);
    }
    else {
        n2 = num2.digits;
    }
    for (size_t i = 0; i < n1.size(); ++i) {
        result.push_back(func(n1[i], n2[i]));
    }
    bool sign = result.back();
    if (sign) {
        result = twosComplement(result);
    }
    InfInt ret(result, sign);
    return ret;
}

bool andOperat(bool b1, bool b2) {
    return b1 & b2;
}

InfInt InfInt::operator&(InfInt other) {
    return operatBitwiseOperators(*this, other, andOperat);
}

bool orOperat(bool b1, bool b2) {
    return b1 | b2;
}

InfInt InfInt::operator|(InfInt other) {
    return operatBitwiseOperators(*this, other, orOperat);
}

bool xorOperat(bool b1, bool b2) {
    return b1 ^ b2;
}

InfInt InfInt::operator^(InfInt other) {
    return operatBitwiseOperators(*this, other, xorOperat);
}

InfInt InfInt::operator&=(InfInt other) {
    return *this = *this & other;
}

InfInt InfInt::operator<<(int mult) {
    if (mult < 0) {
        mult *= -1;
    }
    vector<bool> newNum;
    addZeros(newNum, mult);
    for (size_t i = 0; i < this->digits.size(); ++i) {
        newNum.push_back(this->digits[i]);
    }
    InfInt ret(newNum, this->sign);
    return ret;
}

InfInt InfInt::operator>>(int mult) {
    if (mult < 0) {
        mult * -1;
    }
    vector<bool> newNum;
    for (size_t i = mult; i < this->digits.size(); ++i) {
        newNum.push_back(this->digits[i]);
    }
    // in order to prevent the vector from being empty,
    // in case which mult >= this->digits.size().
    newNum.push_back(0);
    InfInt ret(newNum, this->sign);
    return ret;
}

InfInt InfInt::operator>>=(int mult) {
    return *this = *this >> mult;
}

ostream& operator<<(ostream& os, const InfInt& num) {
    string res = binaryToDecimal(num.digits, num.sign);
    os << res << endl << "Roman: " << decimalToRoman(res) << endl << "Binary: " << vecBinaryToStrBinary(num.digits, num.sign) << endl;
    return os;
}

istream& operator>>(istream& is, InfInt& num) {
    string inputNum;
    is >> inputNum;
    num = InfInt(inputNum);
    return is;
}

InfInt::operator int() const {
    int ret;
    //sizeof int = 4 bytes, byte = 8 bits -> total = 32
    int sizeofIntInBits = 8 * sizeof(int);
    vector<bool> result;
    // 32 bits copy
    for (size_t i = 0; i < this->digits.size(); ++i) {
        if (i >= sizeofIntInBits) {
            break;
        }
        result.push_back(this->digits[i]);
    }
    // converts to string and after to int (-long)
    string numAsDec = binaryToDecimal(result, this->sign);
    ret = stol(numAsDec);
    return ret;
}