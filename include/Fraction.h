#pragma once
#include <iomanip>
#include <numeric>
using namespace std;
#define OLDYAN_FRACTION

struct Fraction{
    long signal;
    long numerator;
    long denominator;
    void normalize(){
        if(denominator){
            if(!numerator){
                signal=denominator=1;
            }
            else{
                if(numerator<0){
                    signal=-1;
                    numerator*=-1;
                }
                if(denominator<0){
                    signal*=-1;
                    denominator*=-1;
                }
                long _gcd=__detail::__gcd(numerator,denominator);
                if(_gcd>1){
                    numerator/=_gcd;
                    denominator/=_gcd;
                }
            }
        }
    }
    Fraction():signal(1),numerator(0),denominator(1){}
    Fraction(long val):signal(val>=0?1:-1),numerator(abs(val)),denominator(1){}
    Fraction(long _numerator,long _denominator):signal(1),numerator(_numerator),denominator(_denominator){
        normalize();
    }
    Fraction(const string&str1,const string&str2):signal(1),numerator(0),denominator(0){
        int idx=0;
        if(!isdigit(str1[idx])&&str1[idx++]=='-')signal=-1;
        while(isdigit(str1[idx]))numerator=numerator*10+str1[idx++]-'0';
        idx=0;
        if(!isdigit(str2[idx])&&str2[idx++]=='-')signal*=-1;
        while(isdigit(str2[idx]))denominator=denominator*10+str2[idx++]-'0';
        normalize();
    }
    Fraction(const string&str):Fraction(str.substr(0,str.find('/')),str.substr(str.find('/')+1,str.size()-str.find('/')-1)){}
    Fraction operator+(const Fraction&other){
        return Fraction(signal*numerator*other.denominator+other.signal*other.numerator*denominator,denominator*other.denominator);
    }
    Fraction&operator+=(const Fraction&other){
        numerator=numerator*other.denominator+signal*other.signal*other.numerator*denominator;
        denominator*=other.denominator;
        normalize();
        return *this;
    }
};

ostream&operator<<(ostream&out,Fraction*frac){
    if(!frac->denominator){
        out<<"invalid fraction\n";
		return out;
    }
    out<<frac->numerator<<"/"<<frac->denominator;
    return out;
}
