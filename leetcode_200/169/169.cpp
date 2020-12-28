#include "utils.h"

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int role,vote=0;
        for(int a:nums){
            if(vote){
                if(role==a)vote++;
                else vote--;
            }
            else{
                role=a;
                vote=1;
            }
        }
        return role;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{2,2,1,1,1,2,2};
    auto ans=sol.majorityElement(nums);
    DBG(ans);

    system("pause");
    return 0;
}
