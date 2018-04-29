//============================================================================
// Name        : myCplusLibrary.cpp
// Author      : Duan Yunde
// Version     :
// Copyright (C) 2018 ChongQing, Duan Yunde.
//        All rights reserved
// Description : , Ansi-style
//============================================================================

#include <iostream>
#include "bigInteger.h"
using namespace std;

int main() {
    BigInt y("127759"), x("94885949696427"), tmp = x;
    cout << x /y << endl;


    /*for(int i = 0; i < 3; ++i){
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
//    BigInt z("34");
//    cout << pow(z, 10).toUllong() << endl;
//           cout << x << 'x' << y << "=" << x * y << endl;
//            << x << '+' << y << "=" << x + y << endl
//            << x << '-' << y << "=" << x - y << endl;
	return 0;
}
