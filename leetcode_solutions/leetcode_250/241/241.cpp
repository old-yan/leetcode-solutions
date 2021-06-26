#include "utils.h"

class Solution {
    int readint(string&s,int&idx){
        int val=0;
        while(isdigit(s[idx])){
            val=val*10+(s[idx++]-'0');
        }
        return val;
    }
    vector<int>nums;
    vector<char>ops;
public:
    vector<int> diffWaysToCompute(string input) {
        int idx=0;
        while(true){
            nums.pb(readint(input,idx));
            if(input[idx])ops.pb(input[idx++]);
            else break;
        }
        int n=nums.size();
        vector<vvi>dp(n,vvi(n));
        REP(i,n){
            REP(j,n-i){
                if(!i)dp[j][j+i].pb(nums[j]);
                else{
                    FOR(k,j,j+i){
                        for(int a:dp[j][k]){
                            for(int b:dp[k+1][j+i]){
                                if(ops[k]=='+')dp[j][j+i].pb(a+b);
                                else if(ops[k]=='-')dp[j][j+i].pb(a-b);
                                else dp[j][j+i].pb(a*b);
                            }
                        }
                    }
                }
            }
        }
        return dp[0][n-1];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string input="2*3-4*5";
    auto ans=sol.diffWaysToCompute(input);
    DBGV(ans);

    system("pause");
    return 0;
}
