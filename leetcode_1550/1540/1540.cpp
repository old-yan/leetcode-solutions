#include "utils.h"

class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        int tobeused[26];
        iota(tobeused,tobeused+26,0);
        REP(i,s.size()){
            int j=(t[i]+26-s[i])%26;
            if(!j)continue;
            if(tobeused[j]>k)return false;
            tobeused[j]+=26;
        }
        return true;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="input";
    string t="ouput";
    int k=9;
    auto ans=sol.canConvertString(s,t,k);
    DBG(ans);

    system("pause");
    return 0;
}
