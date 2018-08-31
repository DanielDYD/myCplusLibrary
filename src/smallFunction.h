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
}

/*judge whether v in the range of 2~rng is prime*/
bool prime(Nlib::ullong v, Nlib::ullong rng);
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

// low bit in right
std::string dec2bin(const std::string &dec);

/*convert the string*/
std::string cvtStr(const std::string &str);

#endif /* SMALLFUNCTION_H_ */
