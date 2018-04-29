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
    ulong tmp = 593749389;
    //cerr << vector<char>::max_size();
    clock_t t;
    cout << "time: ms\n";
    for (int i = 0; i < 10; ++i){
        t = clock();
        cout << tmp << " prime: " << prime(tmp);
        cout << " " << (clock() - t) ;
        t = clock();
        cout << " " << prime(tmp, (ulong)1e9);
        cout << " " << (clock() - t)  << endl;
        tmp += (ulong)1e7;
        //prime(5, 10);
    }
//    prime(5, 5);
//    static vector<char> v;
//    //v.resize((ulong)1e8, 1);
//    cout << v.max_size() << endl;
	return 0;
}
