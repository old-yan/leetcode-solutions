#include "utils.h"

class Solution {
public:
    string fractionToDecimal(int _numerator, int _denominator) {
        if(!_numerator)return "0";
        ll numerator=abs((ll)_numerator);
        ll denominator=abs((ll)_denominator);
        string ans;
        int signal=1;
        if(_numerator<0)signal*=-1;
        if(_denominator<0)signal*=-1;
        if(signal<0)ans+="-";
        ll integer=numerator/denominator;
        ans+=i2s(integer);
        ll rest=numerator%denominator*10;
        if(!rest)return ans;
        ans+=".";
        unordered_map<ll,int>M;
        char c[10000];
        int idx=0;
        while(rest&&!M.count(rest)){
            M[rest]=idx;
            c[idx++]='0'+rest/denominator;
            rest=(rest%denominator)*10;
        }
        if(!rest){
            REP(i,idx)ans+=c[i];
        }
        else{
            REP(i,M[rest])ans+=c[i];
            ans+='(';
            FOR(i,M[rest],idx)ans+=c[i];
            ans+=')';
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int numerator=4;
    int denominator=333;
    auto ans=sol.fractionToDecimal(numerator,denominator);
    DBG(ans);

    system("pause");
    return 0;
}
