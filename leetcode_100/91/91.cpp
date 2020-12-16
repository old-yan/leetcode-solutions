#include "utils.h"

class Solution {
public:
    int numDecodings(string s) {
        int dp[s.size()+1];
        dp[s.size()]=1;
        REPR(i,s.size()-1){
            if(s[i]=='0')dp[i]=0;
            else{
                dp[i]=dp[i+1];
                if(i<s.size()-1&&s2i(s.substr(i,2))<27){
                    dp[i]+=dp[i+2];
                }
            }
        }
        return dp[0];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="226";
    auto ans=sol.numDecodings(s);
    DBG(ans);

    system("pause");
    return 0;
}
