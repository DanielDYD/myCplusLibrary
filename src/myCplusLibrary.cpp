//============================================================================
// Name        : myCplusLibrary.cpp
// Author      : dyd
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <ctime>
#include "smallFunction.h"
using namespace std;

int main() {
    slong tmp = 593749389;
    //cerr << vector<char>::max_size();
    clock_t t;
    for (int i = 0; i < 10; ++i){
        t = clock();
        cout << tmp << " prime: " << prime(tmp);
        cout << " " << (clock() - t) ;
        t = clock();
        cout << " " << prime(tmp, (slong)1e9);
        cout << " " << (clock() - t)  << endl;
        tmp += (slong)1e7;
        //prime(5, 10);
    }
//    prime(5, 5);
//    static vector<char> v;
//    //v.resize((slong)1e8, 1);
//    cout << v.max_size() << endl;
	return 0;
}
