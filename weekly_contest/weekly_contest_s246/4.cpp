#include "utils.h"

class Solution {
    vi idxes[101];
    //传入参数： 值val,左边界l,右边界r
    //看能否在idxes[val]里找到介于[l,r]之间的下标
    bool find(int val,int l,int r){
        auto it=lower_bound(ALL(idxes[val]),l);
        return it!=idxes[val].end()&&*it<=r;
    }
public:
    //本题需要注意到nums[i]的范围：1~100
    //我们可以将每个数字的所有下标存起来，方便查询这个数字在某个区间是否出现过
    //针对每次查询，我们找出1~100中出现的数字，答案就迎刃而解了
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
        REP(i,nums.size())idxes[nums[i]].pb(i);
        vi ans;
        for(auto&q:queries){
            int l=q[0],r=q[1];
            vi seq;
            FOR(i,1,101){
                if(find(i,l,r))seq.pb(i);
            }
            int dif=INT_MAX;
            FOR(j,1,seq.size()){
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

    vi nums{4,5,2,2,7,10};
    vvi queries=makevvi("[[2,3],[0,2],[0,5],[3,5]]");
    auto ans=sol.minDifference(nums,queries);
    DBGV(ans);

    system("pause");
    return 0;
}
