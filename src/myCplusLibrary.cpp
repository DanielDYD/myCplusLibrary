//============================================================================
// Name        : myCplusLibrary.cpp
// Author      : Duan Yunde
// Version     :
// Copyright (C) 2018 ChongQing, Duan Yunde.
//        All rights reserved
// Description : , Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <ctime>
#include "smallFunction.h"
using namespace std;

typedef unsigned long ulong;

int main() {
    /*cout
    <<bin2dec(cvtStr("1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 1 1 1 1 1 1 1 1 1 1 1 1").c_str())<<endl
    <<bin2dec(cvtStr("0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0 1 0 0 0 0 0").c_str())<<endl
    <<bin2dec(cvtStr("1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1").c_str())<<endl
            << endl;*/

    string st = "345998";
    BigInt bg(345), bg1(st);
    cout << bg << endl << bg1 << endl << st[0];

    //cout << bin2dec("1101") << endl << bin2dec(cvtStr("1101").c_str());

    /*BigInt bg("34599897239347219");
    cout << bg.toUllong(5) << endl;*/

    //cout << dec2bin("13");

	return 0;
}
