#include <iostream>
#include "InfInt.h"

InfInt runOp(InfInt num1, InfInt num2, char op) {
    switch (op) {
        case '+': return num1 + num2;
        case '-': return num1 - num2;
        case '*': return num1 * num2;
        case '/': return num1 / num2;
        case '%': return num1 % num2;
        default:
            break;
    }
}

int main() {
    string str1, str2;
    char op;
    InfInt res;
    while (1) {
        cout << "Insert two big integers: ";
        cin >> str1 >> str2;
        cout << "Select an operator to calculate: ";
        cin >> op;
        res = runOp(InfInt(str1), InfInt(str2), op);
        cout << "The result is: " << res;
        cin >> op;
        if (op == 'q') break;
    }

   //int b = (int)InfInt("13");
   //string a;
   //cin >> a;
   //InfInt x(a);
   //InfInt y(b);
   //InfInt w(x % y);
   ////InfInt z(InfInt(0) >= x);
   ////int c = x % y;
   //cout << w << endl;
   //return 0;
}