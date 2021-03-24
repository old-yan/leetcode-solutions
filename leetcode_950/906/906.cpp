#include "utils.h"

const ll units[11]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000,10000000000ll};
class Solution {
    ll left,right,Min,Max;
    int ans=0;
    void dfs(int high,int low,ll cur){
        if(cur>Max)return;
        if(high<low){
            if(cur<Min)return;
            string s=i2s(cur*cur);
            if(isPolindromic(ALL(s))){
                ans++;
            }
        }
        else{
            if(low){
                if(low==high){
                    REP(i,10){
                        dfs(high-1,low+1,cur+units[high]*i);
                    }
                }
                else{
                    REP(i,10){
                        dfs(high-1,low+1,cur+units[high]*i+units[low]*i);
                    }
                }
            }
            else{
                if(low==high){
                    FOR(i,1,10){
                        dfs(high-1,low+1,cur+units[high]*i);
                    }
                }
                else{
                    FOR(i,1,10){
                        dfs(high-1,low+1,cur+units[high]*i+units[low]*i);
                    }
                }
            }
        }
    }
public:
    int superpalindromesInRange(string _left, string _right) {
        left=s2i(_left),right=s2i(_right);
        Min=ceil(sqrt(left));
        Max=sqrt(right);
        FOR(l,i2s(Min).size(),i2s(Max).size()+1){
            dfs(l-1,0,0);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string left="111";
    string right="231";
    auto ans=sol.superpalindromesInRange(left,right);
    DBG(ans);

    system("pause");
    return 0;
}
