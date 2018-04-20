/*
 * bigInteger.cpp
 *
 *  Created on: 2018��4��19��
 *      Author: dyd
 */
#include "bigInteger.h"
#include <cstdlib>
#include <sstream>

const BigInt::bint BigInt::BASE;
const int BigInt::WIDTH;

BigInt::BigInt(const string &str){
    *this = str;
}

BigInt& BigInt::operator =(const string &str){
    ctt.clear();
    // chip in the big integer
    bint chip, len = (str.length() - 1) / WIDTH + 1;
    for(int i = 0; i < len; ++i){
        int end = str.length() - i * WIDTH;
        int start = std::max(0, end - WIDTH);
        std::stringstream sstr(str.substr(start, end - start));
        sstr >> chip;
        ctt.push_back(chip);
    }
    return *this;
}

BigInt& BigInt::operator =(const long long &num){
    ctt.clear();
    long long n = num;
    do{
        ctt.push_back(n % BASE);
        n /= BASE;
    } while(n > 0);
    return *this;
}

bool operator >(const BigInt &lft, const BigInt &rht){
    if (lft.ctt.size() != rht.ctt.size())
        return lft.ctt.size() > rht.ctt.size();
    for(int i = lft.ctt.size() - 1; i >= 0; --i)
        if (lft.ctt[i] != rht.ctt[i])
            return lft.ctt[i] > rht.ctt[i];
    return false; // equal
}

BigInt operator +(const BigInt &lft, const BigInt &rht){
    BigInt ans;
    // carry number is crr
    BigInt::bint crr = 0;
    for(unsigned int i = 0; ; ++i){
        if (crr == 0 && i >= lft.ctt.size() && i >= rht.ctt.size())
            break;
        BigInt::bint tmp = crr;
        if (i < lft.ctt.size()) tmp += lft.ctt[i];
        if (i < rht.ctt.size()) tmp += rht.ctt[i];
        ans.ctt.push_back(tmp % BigInt::BASE);
        crr = tmp / BigInt::BASE;
    }
    return ans;
}

BigInt& BigInt::operator +=(const BigInt &rht){
    BigInt &ans = *this;
    // carry number in crr
    bint crr = 0;
    for(unsigned int i = 0; ; ++i){
        if (crr == 0 && i >= ctt.size() && i >= rht.ctt.size())
            break;
        bint tmp = crr;
        if (i < ctt.size()) tmp += ctt[i];
        if (i < rht.ctt.size()) tmp += rht.ctt[i];
        if (i >= ctt.size()){
            ans.ctt.push_back(tmp % BigInt::BASE);
        } else ctt[i] = tmp % BigInt::BASE;
        crr = tmp / BigInt::BASE;
    }
    return ans;
}

std::ostream& BigInt::output(ostream &out) const{
    out << ctt.back();
    for(int i = ctt.size() - 2; i >= 0; --i){
        out.width(BigInt::WIDTH);
        out.fill('0');
        out << ctt[i];
    }
    return out;
}

BigInt operator -(const BigInt &lft, const BigInt &rht){
    if (lft < rht){
        std::cerr << "left value is smaller than right\n";
        exit(EXIT_FAILURE);
    }
    BigInt ans;
    // borrow number is brr
    BigInt::bint brr = 0;
    for (unsigned int i = 0; i < lft.ctt.size(); ++i){
        BigInt::bint tmp = lft.ctt[i] - brr;
        if (i < rht.ctt.size()) tmp -= rht.ctt[i];
        if (tmp >= 0) brr = 0;
        else{
            brr = 1; tmp += BigInt::BASE;
        }
        ans.ctt.push_back(tmp);
    }
    ans.clean();
    return ans;
}

BigInt& BigInt::operator -=(const BigInt &rht){
    BigInt &lft = *this, &ans = *this;
    if (lft < rht){
            std::cerr << "left value is smaller than right\n";
            exit(EXIT_FAILURE);
        }
        //BigInt ans;
        // borrow number is brr
        BigInt::bint brr = 0;
        for (unsigned int i = 0; i < lft.ctt.size(); ++i){
            BigInt::bint tmp = lft.ctt[i] - brr;
            if (i < rht.ctt.size()) tmp -= rht.ctt[i];
            if (tmp >= 0) brr = 0;
            else{
                brr = 1; tmp += BigInt::BASE;
            }
            ans.ctt[i] = tmp;
        }
        ans.clean();
        return ans;
}

BigInt operator *(const BigInt &lft, const BigInt &rht){
    BigInt ans;
    BigInt::bint tmp;
    ans.ctt.resize(lft.ctt.size() + rht.ctt.size(), 0);
    for(unsigned int i = 0; i < rht.ctt.size(); ++i)
        for(unsigned int j = 0; j < lft.ctt.size(); ++j){
            tmp = ans.ctt[i + j] + rht.ctt[i] * lft.ctt[j];
            if (tmp >= BigInt::BASE){
                ans.ctt[i + j + 1] += tmp / BigInt::BASE;
                tmp %= BigInt::BASE;
            }
            ans.ctt[i + j] = tmp;
        }
    ans.clean();
    return ans;
}

BigInt& BigInt::operator *=(const BigInt &rht){
    return *this = *this * rht;
}

BigInt operator /(const BigInt &lft, const BigInt &rht){
    BigInt ans, tmp(0);
    ans.ctt.resize(lft.ctt.size(), 0);
    for(int i = lft.ctt.size() - 1; i >= 0; --i){
        tmp *= BigInt::BASE;
        tmp.ctt[0] = lft.ctt[i];
        while(tmp >= rht){
            tmp -= rht;
            ++ans.ctt[i];
        }
    }
    ans.clean();
    return ans;
}

BigInt& BigInt::operator /=(const BigInt &rht){
    return *this = *this / rht;
}

BigInt operator %(const BigInt &lft, const BigInt &rht){
    return lft - lft / rht * rht;
}

BigInt& BigInt::operator %=(const BigInt &rht){
    return *this = *this - *this / rht * rht;
}

std::ostream& operator <<(std::ostream& out, const BigInt &x){
    return x.output(out);
}

std::istream& operator >>(std::istream &in, BigInt &x){
    std::string s;
    if (!(in >> s)){
        std::cerr << "bad data in stream\n";
        exit(EXIT_FAILURE);
    }
    x = s;
    return in;
}

bool operator <(const BigInt &lft, const BigInt &rht){
    return rht > lft;
}

bool operator <=(const BigInt &lft, const BigInt &rht){
    return !(lft > rht);
}

bool operator >=(const BigInt &lft, const BigInt &rht){
    return !(rht > lft);
}

bool operator !=(const BigInt &lft, const BigInt &rht){
    return rht > lft || lft > rht;
}

bool operator ==(const BigInt &lft, const BigInt &rht){
    return !(rht > lft) && !(lft > rht);
}
