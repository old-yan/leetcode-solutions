#include "utils.h"

class Solution {
public:
    int translateNum(int num) {
        string s=i2s(num);
        int n=s.size();
        int dp[n+1];
        dp[n]=1;
        REPR(i,n-1){
            dp[i]=dp[i+1];
            if(s[i]!='0'&&isdigit(s[i+1])){
                int val=(s[i]-'0')*10+(s[i+1]-'0');
                if(val<26)dp[i]+=dp[i+2];
            }
        }
        return dp[0];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int num=12258;
    auto ans=sol.translateNum(num);
    DBG(ans);

    system("pause");
    return 0;
}
