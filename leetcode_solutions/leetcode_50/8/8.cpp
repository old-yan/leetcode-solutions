#include "utils.h"

class Solution {
public:
    int myAtoi(string s) {
        int idx,signal=1;
        ll val=0;
        for(idx=0;idx<s.size();idx++)if(s[idx]!=' ')break;
        if(s[idx]!='+'&&s[idx]!='-'&&!isdigit(s[idx]))return 0;
        if(s[idx]=='+'||s[idx]=='-'){
            signal=s[idx]=='+'?1:-1;
            if(!isdigit(s[++idx]))return 0;
        }
        while(isdigit(s[idx])){
            val=val*10+s[idx]-'0';
            idx++;
            if(val>INT_MAX)break;
        }
        val*=signal;
        if(val>INT_MAX)return INT_MAX;
        if(val<INT_MIN)return INT_MIN;
        return val;
    }
};

int main()
{
    Solution sol;

    string s="   -42";
    auto ans=sol.myAtoi(s);
    DBG(ans);

    system("pause");
    return 0;
}
