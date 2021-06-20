#include "utils.h"

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans,cnt=0;
        for(int a:nums){
            if(cnt){
                if(a==ans)cnt++;
                else cnt--;
            }
            else{
                ans=a;
                cnt=1;
            }
        }
        return count(ALL(nums),ans)>nums.size()/2?ans:-1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,2,5,9,5,9,5,5,5};
    auto ans=sol.majorityElement(nums);
    DBG(ans);

    system("pause");
    return 0;
}
