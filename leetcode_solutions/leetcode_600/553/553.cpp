#include "utils.h"

class Solution {
    long double dp[10][10][2];
    int splitpoint[10][10][2];
    vi nums;
    string make_string(int l,int r,bool lookfor_biggest){
        if(l==r)return i2s(nums[l]);
        int k=splitpoint[l][r][lookfor_biggest];
        string a=make_string(l,k,lookfor_biggest);
        string b=make_string(k+1,r,!lookfor_biggest);
        if(k+1==r)return a+"/"+b;
        else return a+"/("+b+")";
    }
public:
    string optimalDivision(vector<int>&_nums) {
        nums=_nums;
        REP(i,nums.size()){
            REP(l,nums.size()-i){
                if(!i)dp[l][l+i][0]=dp[l][l+i][1]=nums[l];
                else{
                    dp[l][l+i][0]=INT_MAX;
                    FOR(k,l,l+i){
                        if(chmin(dp[l][l+i][0],dp[l][k][0]/dp[k+1][l+i][1])){
                            splitpoint[l][l+i][0]=k;
                        }
                    }
                    dp[l][l+i][1]=INT_MIN;
                    FOR(k,l,l+i){
                        if(chmax(dp[l][l+i][1],dp[l][k][1]/dp[k+1][l+i][0])){
                            splitpoint[l][l+i][1]=k;
                        }
                    }
                }
            }
        }
        string ans=make_string(0,nums.size()-1,true);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1000,100,10,2};
    auto ans=sol.optimalDivision(nums);
    DBG(ans);

    system("pause");
    return 0;
}
