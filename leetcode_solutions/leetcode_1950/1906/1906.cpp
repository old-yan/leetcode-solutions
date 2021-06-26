#include "utils.h"

class Solution {
    vi appear[101];
    bool check(int val,int l,int r){
        auto it=lower_bound(ALL(appear[val]),l);
        return it!=appear[val].end()&&*it<=r;
    }
public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
        REP(i,nums.size())appear[nums[i]].pb(i);
        vi ans;
        for(auto&q:queries){
            int l=q[0],r=q[1];
            static int seq[101],len;
            len=0;
            FOR(i,1,101){
                if(check(i,l,r))seq[len++]=i;
            }
            int dif=INT_MAX;
            FOR(j,1,len){
                chmin(dif,seq[j]-seq[j-1]);
            }
            if(dif==INT_MAX)ans.pb(-1);
            else ans.pb(dif);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,3,4,8};
    vvi queries=makevvi("[[0,1],[1,2],[2,3],[0,3]]");
    auto ans=sol.minDifference(nums,queries);
    DBGV(ans);

    system("pause");
    return 0;
}
