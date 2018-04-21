/*
 * smallFunction.cpp
 *
 *  Created on: 2018Äê4ÔÂ20ÈÕ
 *      Author: dyd
 */
#include "smallFunction.h"
#include <vector>
#include <cmath>
//#include <iostream>

/*judge whether v in the range of 2~rng is prime*/
bool prime(slong v, slong rng){
    static slong rg = 0;
    static std::vector<char> flg;
    if (rg < rng){
        rg = rng;
        flg.resize(rng, 1);
        for (slong i = 2; i < (slong)sqrt(rng); ++i) {
            if (flg[i])
                for (int j = i; j * i < rng; ++j)
                    flg[i * j] = 0;
        }
    }
    return flg[v];
}

/*judge whether v is prime*/
bool prime(slong v){
    for(slong i = 2; i <= (slong)sqrt(v); ++i)
        if (v % i == 0) return false;
    return true;
}



