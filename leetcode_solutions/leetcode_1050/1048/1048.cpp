#include "utils.h"

class Solution {
    bool isPre(string&x,string&y){
        if(x.size()!=y.size()-1)return false;
        bool skip=false;
        for(int i=0,j=0;i<x.size();i++,j++){
            if(x[i]!=y[j]){
                if(skip)return false;
                skip=true;
                if(x[i]!=y[++j])return false;
            }
        }
        return true;
    }
public:
    int longestStrChain(vector<string>& words) {
        sort(ALL(words),[](string&x,string&y){return x.size()<y.size();});
        int n=words.size();
        int dp[n];
        fill(dp,dp+n,1);
        REP(i,n){
            REP(j,i){
                if(isPre(words[j],words[i])){
                    chmax(dp[i],dp[j]+1);
                }
            }
        }
        return *max_element(dp,dp+n);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<string>words{
        "a","b","ba","bca","bda","bdca"
    };
    auto ans=sol.longestStrChain(words);
    DBG(ans);

    system("pause");
    return 0;
}
