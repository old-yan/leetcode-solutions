#include "Trie.h"
#include "utils.h"

BiTrie T;
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        vi idxes(queries.size());
        iota(ALL(idxes),0);
        sort(ALL(idxes),[&](int x,int y){return queries[x][1]<queries[y][1];});
        sort(ALL(nums));
        int cursor=0;
        vi ans(queries.size(),-1);
        T.clear();
        for(auto idx:idxes){
            int x=queries[idx][0],m=queries[idx][1];
            while(cursor<nums.size()&&nums[cursor]<=m){
                T.insert(nums[cursor++]);
            }
            if(cursor){
                ans[idx]=T.MaxXor(0x7fffffff^x);
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{0,1,2,3,4};
    vvi queries=makevvi("[[3,1],[1,3],[5,6]]");
    auto ans=sol.maximizeXor(nums,queries);
    DBGV(ans);

    system("pause");
    return 0;
}
