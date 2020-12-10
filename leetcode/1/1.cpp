#include "utils.h"

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>M;
        REP(i,nums.size()){
            auto find=M.find(target-nums[i]);
            if(find!=M.end()){
                return {find->second,int(i)};
            }
            M[nums[i]]=i;
        }
        return {};
    }
};

int main(){
    Solution sol;

    vi  nums{2,7,11,15};
    DBGV(nums);
    int target=9;
    DBG(target);
    auto ans=sol.twoSum(nums,target);
    DBGV(ans);


    system("pause");
}