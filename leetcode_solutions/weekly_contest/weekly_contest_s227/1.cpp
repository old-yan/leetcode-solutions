#include "utils.h"

class Solution {
public:
    //在copy数组中将nums数组重复两次，然后看copy数组中存不存在源数组
    bool check(vector<int>& nums) {
        vi copy=nums;
        copy.insert(copy.end(),ALL(nums));
        //排序获得源数组
        sort(ALL(nums));
        for(int i=0;i<nums.size();i++){
            bool same=true;
            for(int j=0;j<nums.size();j++){
                if(copy[i+j]!=nums[j])same=false;
            }
            if(same)return true;
        }
        return false;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{2,1,3,4};
    auto ans=sol.check(nums);
    DBG(ans);

    system("pause");
    return 0;
}
