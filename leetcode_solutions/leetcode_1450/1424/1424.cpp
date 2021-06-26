#include "utils.h"

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int Max=0;
        int total=0;
        REP(i,nums.size()){
            chmax(Max,int(i+nums[i].size()-1));
            total+=nums[i].size();
        }
        vvi lines(Max+1);
        REP(i,nums.size()){
            REP(j,nums[i].size()){
                lines[i+j].pb(nums[i][j]);
            }
        }
        vi ans;
        ans.reserve(total);
        for(auto&line:lines){
            ans.insert(ans.end(),ALLR(line));
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi nums=makevvi("[[1,2,3],[4,5,6],[7,8,9]]");
    auto ans=sol.findDiagonalOrder(nums);
    DBGV(ans);

    system("pause");
    return 0;
}
