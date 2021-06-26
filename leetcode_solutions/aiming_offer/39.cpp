#include "utils.h"

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int num,cnt=0;
        for(int a:nums){
            if(cnt){
                if(a==num)cnt++;
                else cnt--;
            }
            else{
                num=a;
                cnt=1;
            }
        }
        return num;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1, 2, 3, 2, 2, 2, 5, 4, 2};
    auto ans=sol.majorityElement(nums);
    DBG(ans);

    system("pause");
    return 0;
}
