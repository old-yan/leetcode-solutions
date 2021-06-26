#include "utils.h"

class Solution {
    pair<int,int>dp[40][40];
    pair<int,int> calc(int l,int r,string&s){
        if(dp[l][r].first||dp[l][r].second)return dp[l][r];
        if(l==r){
            if(s[l]=='0')return dp[l][r]={1,0};
            else return dp[l][r]={0,1};
        }
        else{
            for(int last=l+1;last<r;last+=2){
                auto [l0,l1]=calc(l,last-1,s);
                auto [r0,r1]=calc(last+1,r,s);
                if(s[last]=='&'){
                    dp[l][r].first+=l0*r0+l0*r1+l1*r0;
                    dp[l][r].second+=l1*r1;
                }
                else if(s[last]=='|'){
                    dp[l][r].first+=l0*r0;
                    dp[l][r].second+=l0*r1+l1*r0+l1*r1;
                }
                else{
                    dp[l][r].first+=l0*r0+l1*r1;
                    dp[l][r].second+=l0*r1+l1*r0;
                }
            }
            return dp[l][r];
        }
    }
public:
    int countEval(string s, int result) {
        memset(dp,0,sizeof(dp));
        auto res=calc(0,s.size()-1,s);
        return result?res.second:res.first;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="1^0|0|1";
    int result=0;
    auto ans=sol.countEval(s,result);
    DBG(ans);

    system("pause");
    return 0;
}
