//============================================================================
// Name        : smallFunction.cpp
// Version     :
// Copyright (C) 2018 ChongQing, Duan Yunde.
//        All rights reserved
// Description : , Ansi-style
//============================================================================

#include "smallFunction.h"
#include"simplify.h"
#include <vector>
#include<sstream>
#include <cmath>
#include <iostream>
#include<iomanip>

typedef std::vector<std::vector<int>> matrix;

using std::string;
using Nlib::ullong;
using Nlib::llong;

// output 2D array mtx
void outMtx(const matrix &mtx, std::ostream &out, int wdt)
{
    out << std::left;
    rep(i, 0, static_cast<int>(mtx.size())){
        rep(j, 0, static_cast<int>(mtx[i].size()))
            out << std::setw(wdt) << mtx[i][j];
        out << std::endl;
    }
    out << std::right;
}

// output the matrix using separator spr
void outMtx(const matrix &mtx, std::ostream &out, string spr){
    int id;
    rep(i, 0, static_cast<int>(mtx.size())){
        id = static_cast<int>(mtx[i].size());
        rep(j, 0, id)
            out << mtx[i][j] << (j == id - 1 ? "" : spr);
        out << std::endl;
    }
}

/* input 2D array to mtx, map relation:
 * mtx[0][0] mtx[0][1] ...
 * mtx[1][0] mtx[1][1] ...
*/
void inMtx(matrix &mtx, std::istream &in)
{
    int v, i = 0;
    for(string str; std::getline(in, str); ++i){
        mtx.push_back(std::vector<int>());
        std::istringstream sst(str);
        while(sst >> v) mtx[i].push_back(v);
    }
}

/*judge whether v in the range of 2~rng is prime*/
bool prime(size_t v, size_t rng){
    static size_t rg = 0;
    static std::vector<bool> flg;
    if (rg < rng){
        rg = rng;
        flg.resize(rng, 1);
        for (size_t i = 2; i <= (size_t)sqrt(rng); ++i) {
            if (flg[i])
                for (size_t j = i; j * i <= rng; ++j)
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
        ans.push_back((int)(decBg % 2).toUllong(1) + '0');
        decBg /= 2;
    }

    return cvtStr(ans);
}

/*convert the string*/
string cvtStr(const string &str){
    string ans = str;
    size_t n = str.size() - 1;
    for(size_t i = 0; i < str.size(); ++i){
        ans[n--] = str[i];
    }
    return ans;
}


