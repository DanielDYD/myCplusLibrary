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

int main() {
    BigInt y("7893497575"), x("7236897878"), tmp;
    for(int i = 0; i < 10; ++i){
        cout << x << '>' << y << "=" << (x > y) << endl;
        cout << x << ">=" << y << "=" << (x >= y) << endl;
        cout << x << '<' << y << "=" << (x < y) << endl;
        cout << x << "<=" << y << "=" << (x <= y) << endl;
        cout << x << "==" << y << "=" << (x == y) << endl;
        cout << x << "!=" << y << "=" << (x != y) << endl;
//        tmp = x; tmp %= y;
//        cout << x << '~' << y << "=" << tmp << endl;
        x += (int)1e8;
    }
//           cout << x << 'x' << y << "=" << x * y << endl;
//            << x << '+' << y << "=" << x + y << endl
//            << x << '-' << y << "=" << x - y << endl;
	return 0;
}
