//============================================================================
// Name        : smallFunction.cpp
// Version     :
// Copyright (C) 2018 ChongQing, Duan Yunde.
//        All rights reserved
// Description : , Ansi-style
//============================================================================

#include "smallFunction.h"
#include <vector>
//#include<string>
#include <cmath>
//#include <iostream>

typedef unsigned long long ullong;

using std::string;

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

/*binary to decimal, bin[0] is low bit*/
BigInt bin2dec(const char *bin){
    BigInt ans(0), tmp(1);
    for(int i = 0; bin[i] != '\0'; ++i){
        if(bin[i] == '1')
            ans += tmp;
        if(bin[i] == '1' || bin[i] == '0')
            tmp *= 2;
    }
    return ans;
}

string dec2bin(const string &dec){
    BigInt decBg(dec);
    string ans;
    for(; decBg != 0;){
        ans.push_back((decBg % 2).toUllong(1) + '0');
        decBg /= 2;
    }

    return cvtStr(ans);
}

/*convert the string*/
string cvtStr(const string &str){
    string ans = str;
    long n = str.size() - 1;
    for(size_t i = 0; i < str.size(); ++i){
        ans[n--] = str[i];
    }
    return ans;
}


