//============================================================================
// Name        : smallFunction.h
// Version     :
// Copyright (C) 2018 ChongQing, Duan Yunde.
//        All rights reserved
// Description : , Ansi-style
//============================================================================

#ifndef SMALLFUNCTION_H_
#define SMALLFUNCTION_H_

#include<cstring>
#include"bigInteger.h"

namespace Nlib{
    typedef unsigned long long ullong;
    typedef long long llong;
}

// compute s hamming weight in low 64 bits, that is popcount
inline int weight(const Nlib::ullong &s)
{
    using Nlib::ullong;
    ullong x = s;
    static const ullong m1 = 0x5555555555555555; //binary: 0101...
    static const ullong m2 = 0x3333333333333333; //binary: 00110011..
    static const ullong m4 = 0x0f0f0f0f0f0f0f0f; //binary:  4 zeros,  4 ones ...
    static const ullong h01 = 0x101010101010101; //the sum of 256 to the power of 0,1,2,3...
    x -= (x >> 1) & m1;             //put count of each 2 bits into those 2 bits
    x = (x & m2) + ((x >> 2) & m2); //put count of each 4 bits into those 4 bits
    x = (x + (x >> 4)) & m4;        //put count of each 8 bits into those 8 bits
    x = (x * h01) >> 56;  //returns left 8 bits of x + (x<<8) + (x<<16) + (x<<24) +
    // (x<<32) + (x<<40) + (x<<48) + (x<<56)
    return static_cast<int>(x);
}

/*judge whether v in the range of 2~rng is prime*/
bool prime(size_t v, size_t rng);
/*judge whether v is prime*/
bool prime(Nlib::ullong v);

// output 2D array mtx
void outMtx(const std::vector<std::vector<int>> &mtx, std::ostream &out, int wdt = 8);

// output the matrix using separator spr
void outMtx(const std::vector<std::vector<int>> &mtx, std::ostream &out, std::string spr);

/* input 2D array to mtx, map relation:
 * mtx[0][0] mtx[0][1] ...
 * mtx[1][0] mtx[1][1] ...
*/
void inMtx(std::vector<std::vector<int>> &mtx, std::istream &in);

// return the location pointing first non-delimiter char, otherwise return 0
inline int stringRemoveDelimiter(char delimiter, const char *string) {
  int string_start = 0;

  while (string[string_start] == delimiter) {
    string_start++;
  }

  if (string_start >= static_cast<int>(strlen(string) - 1)) {
    return 0;
  }

  return string_start;
}

/*binary to decimal, bin[0] is low bit*/
BigInt bin2dec(const char *bin);

// low bit in right, "13" return "1101"
std::string dec2bin(const std::string &dec);

/*convert the string*/
std::string cvtStr(const std::string &str);

#endif /* SMALLFUNCTION_H_ */
