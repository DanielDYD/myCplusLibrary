//============================================================================
// Name        : smallFunction.cpp
// Version     :
// Copyright (C) 2018 ChongQing, Duan Yunde.
//        All rights reserved
// Description : , Ansi-style
//============================================================================

#include "smallFunction.h"
#include <vector>
#include <cmath>
//#include <iostream>

typedef unsigned long long ullong;

/*judge whether v in the range of 2~rng is prime*/
bool prime(ullong v, ullong rng){
    static ullong rg = 0;
    static std::vector<char> flg;
    if (rg < rng){
        rg = rng;
        flg.resize(rng, 1);
        for (ullong i = 2; i <= (ullong)sqrt(rng); ++i) {
            if (flg[i])
                for (ullong j = i; j * i <= rng; ++j)
                    flg[i * j] = 0;
        }
    }
    return flg[v];
}

/*judge whether v is prime*/
bool prime(ullong v){
    for(ullong i = 2; i <= (ullong)sqrt(v); ++i)
        if (v % i == 0) return false;
    return true;
}



