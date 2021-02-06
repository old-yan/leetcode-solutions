#include "utils.h"

class Solution {
public:
    int numDecodings(string s) {
        ll dp[s.size()];
        #define a(i) (i>=0?dp[i]:1)
        REP(i,s.size()){
            if(s[i]=='*')dp[i]=a(i-1)*9;
            else if(s[i]!='0')dp[i]=a(i-1);
            else dp[i]=0;
            if(i){
                if(s[i]=='*'){
                    if(s[i-1]=='*')dp[i]+=a(i-2)*15;
                    else if(s[i-1]=='1')dp[i]+=a(i-2)*9;
                    else if(s[i-1]=='2')dp[i]+=a(i-2)*6;
                }
                else if(s[i]<='6'){
                    if(s[i-1]=='*')dp[i]+=a(i-2)*2;
                    else if(s[i-1]=='1')dp[i]+=a(i-2);
                    else if(s[i-1]=='2')dp[i]+=a(i-2);
                }
                else{
                    if(s[i-1]=='*'||s[i-1]=='1')dp[i]+=a(i-2);
                }
            }
            dp[i]%=MOD;
        }
        return dp[s.size()-1];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="1*";
    auto ans=sol.numDecodings(s);
    DBG(ans);

    system("pause");
    return 0;
}
