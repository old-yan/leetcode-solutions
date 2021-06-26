#include "utils.h"

class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n=s.size();
        int mask[n+1];
        mask[0]=0;
        REP(i,n){
            mask[i+1]=1<<(s[i]-'a');
        }
        partial_sum(mask,mask+n+1,mask,[](int x,int y){return x^y;});
        vector<bool>ans;
        for(auto&q:queries){
            int left=q[0],right=q[1],k=q[2];
            int sum=mask[right+1]^mask[left];
            int need=__builtin_popcount(sum)/2;
            ans.pb(need<=k);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="abcda";
    vvi queries=makevvi("[[3,3,0],[1,2,0],[0,3,1],[0,3,2],[0,4,1]]");
    auto ans=sol.canMakePaliQueries(s,queries);
    DBGV(ans);

    system("pause");
    return 0;
}
