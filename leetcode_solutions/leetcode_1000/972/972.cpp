#include "Fraction.h"
#include "utils.h"

class Solution {
    Fraction fun(string&s){
        int i=s.find('.');
        if(i<0)return Fraction(s2i(s));
        if(i==s.size()-1)return Fraction(s2i(s.substr(0,s.size()-1)));
        Fraction a(s2i(s.substr(0,i)));
        int j=s.find('(');
        if(j<0){
            Fraction b(s2i(s.substr(i+1)),pow(10,s.size()-i-1));
            return a+b;
        }
        else if(j==i+1){
            Fraction c(s2i(s.substr(j+1,s.size()-j-2)),pow(10,s.size()-j-2)-1);
            return a+c;
        }
        else{
            Fraction b(s2i(s.substr(i+1,j-i-1)),pow(10,j-i-1));
            Fraction c(s2i(s.substr(j+1,s.size()-j-2)),pow(10,s.size()-j-2)-1);
            return a+b+c;
        }
    }
public:
    bool isRationalEqual(string s, string t) {
        auto a=fun(s);
        auto b=fun(t);
        cout<<"hello";
        return a.denominator==b.denominator&&a.numerator==b.numerator&&a.signal==b.signal;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="0.9(9)";
    string t="1.";
    auto ans=sol.isRationalEqual(s,t);
    DBG(ans);

    system("pause");
    return 0;
}
