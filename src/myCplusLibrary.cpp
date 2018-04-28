//============================================================================
// Name        : myCplusLibrary.cpp
// Author      : dyd
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "bigInteger.h"
using namespace std;

int main() {/*
    BigInt y("789349757"), x("7236897878"), tmp = x;
    for(int i = 0; i < 3; ++i){
        cout << x << '>' << y << "=" << (x > y) << endl;
        cout << x << ">=" << y << "=" << (x >= y) << endl;
        cout << x << '<' << y << "=" << (x < y) << endl;
        cout << x << "<=" << y << "=" << (x <= y) << endl;
        cout << x << "==" << y << "=" << (x == y) << endl;
        cout << x << "!=" << y << "=" << (x != y) << endl;
        cout << x << '+' << y << "=" << (x + y) << endl;
        cout << x << "+=" << y << "=" << (tmp += y) << endl;
        tmp = x;
        cout << x << '-' << y << "=" << (x - y) << endl;
        cout << x << "-=" << y << "=" << (tmp -= y) << endl;
        tmp = x;
        cout << x << '*' << y << "=" << (x * y) << endl;
        cout << x << "*=" << y << "=" << (tmp *= y) << endl;
        tmp = x;
        cout << x << '/' << y << "=" << (x / y) << endl;
        cout << x << "/=" << y << "=" << (tmp /= y) << endl;
        tmp = x;
        cout << x << '%' << y << "=" << (x % y) << endl;
        cout << x << "%=" << y << "=" << (tmp %= y) << endl;
//        tmp = x; tmp %= y;
//        cout << x << '~' << y << "=" << tmp << endl;
        x += (int)1e8;
        tmp = x;
    }*/
    BigInt z("34");
    cout << pow(z, 10).toUllong() << endl;
//           cout << x << 'x' << y << "=" << x * y << endl;
//            << x << '+' << y << "=" << x + y << endl
//            << x << '-' << y << "=" << x - y << endl;
	return 0;
}
