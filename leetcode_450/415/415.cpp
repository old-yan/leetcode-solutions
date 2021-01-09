#include "utils.h"

class Solution {
public:
    string addStrings(string num1, string num2) {
        vi v(max(num1.size(),num2.size()),0);
        REP(i,num1.size()){
            v[num1.size()-1-i]+=num1[i]-'0';
        }
        REP(i,num2.size()){
            v[num2.size()-1-i]+=num2[i]-'0';
        }
        int jinwei=0;
        REP(i,v.size()){
            v[i]+=jinwei;
            jinwei=v[i]/10;
            v[i]%=10;
        }
        if(jinwei)v.pb(1);
        string ans;
        for(int a:v)ans+='0'+a;
        reverse(ALL(ans));
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string num1="123";
    string num2="456";
    auto ans=sol.addStrings(num1,num2);
    DBG(ans);

    system("pause");
    return 0;
}
