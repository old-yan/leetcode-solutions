#include "utils.h"

class Solution {
    vi next;
public:
    int triangleNumber(vector<int>& nums) {
        sort(ALL(nums));
        next=next_different(nums);
        int ans=0;
        for(int i=nums[0]?0:next[0];i<nums.size();i++){
            for(int j=i+1,k=i+1;j+1<nums.size();j=next[j]){
                while(k<nums.size()&&nums[k]<nums[j]+nums[i])k=next[k];
                ans+=(k*2-next[j]-j-1)*(next[j]-j)/2;
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{2,2,2,3,3,3,4,4,4};
    auto ans=sol.triangleNumber(nums);
    DBG(ans);

    system("pause");
    return 0;
}
