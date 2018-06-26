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

/*judge whether v in the range of 2~rng is prime*/
bool prime(unsigned long long v, unsigned long long rng);
/*judge whether v is prime*/
bool prime(unsigned long long v);

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
