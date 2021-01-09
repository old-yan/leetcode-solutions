#include "utils.h"

class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans;
        zkwMinTree T(num.size());
        REP(i,num.size())T.set(i,num[i]);
        REP(i,num.size()){
            if(i+k==num.size())break;
            int candidate=T(i+1,i+k);
            if(candidate<num[i])k--;
            else ans+=num[i];
        }
        int zero=0;
        REP(i,ans.size()){
            if(ans[i]=='0')zero++;
            else break;
        }
        if(zero==ans.size())return "0";
        return ans.substr(zero,ans.size()-zero);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string num="1432219";
    int k=3;
    auto ans=sol.removeKdigits(num,k);
    DBG(ans);

    system("pause");
    return 0;
}
