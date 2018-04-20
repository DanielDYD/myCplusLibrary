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
    BigInt y("78934"), x("7236823");
    cout << x << 'x' << y << "=" << x * y << endl
            << x << '/' << y << "=" << x / y << endl
            << x << '+' << y << "=" << x + y << endl
            << x << '-' << y << "=" << x - y << endl;
	return 0;
}
