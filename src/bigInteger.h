/*
 * bigInteger.h
 *
 *  Created on: 2018Äê4ÔÂ19ÈÕ
 *      Author: dyd
 */

#ifndef BIGINTEGER_H_
#define BIGINTEGER_H_
#include <vector>
#include <string>

class BigInt{
private:
    typedef long long bint; // type for per chip
    // values below can be adjusted
    static const bint BASE = (bint)1e9;
    static const int WIDTH = 9;
    /*
    typedef int bint; // type for per chip
    static const bint BASE = (bint)1e4;
    static const int WIDTH = 4;
    */

    // low digit in ctt[0]
    std::vector<bint> ctt; // save the content

public:
    BigInt(){}
    BigInt(const long long &num){
        *this = num;
    }
    BigInt(const std::string &);
    BigInt& operator =(const std::string &);
    BigInt& operator =(const long long &);
    friend bool operator >(const BigInt &, const BigInt &);
    friend BigInt operator +(const BigInt &, const BigInt &);
    BigInt& operator +=(const BigInt &);
    std::ostream& output(std::ostream&) const;
    friend BigInt operator -(const BigInt &, const BigInt &);
    BigInt& operator -=(const BigInt &);
    friend BigInt operator *(const BigInt &, const BigInt &);
    BigInt& operator *=(const BigInt &);
    friend BigInt operator /(const BigInt &, const BigInt &);
    BigInt& operator /=(const BigInt &);
    friend BigInt operator %(const BigInt &, const BigInt &);
    BigInt& operator %=(const BigInt &);
private:
    void clean(){
        for(int i = ctt.size() - 1; i > 0; --i)
            if (ctt[i] == 0) ctt.pop_back();
            else return;
    }
};

std::ostream& operator <<(std::ostream &, const BigInt &);
std::istream& operator >>(std::istream &, BigInt &);
bool operator <(const BigInt &, const BigInt &);
bool operator <=(const BigInt &, const BigInt &);
bool operator >=(const BigInt &, const BigInt &);
bool operator !=(const BigInt &, const BigInt &);
bool operator ==(const BigInt &, const BigInt &);
#endif /* BIGINTEGER_H_ */
