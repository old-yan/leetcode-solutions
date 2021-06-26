#include "utils.h"

class Solution {
public:
    //针对数据范围，暴力搜索即可
    int sumOfUnique(vector<int>& nums) {
        int ans=0;
        for(int a:nums){
            int cnt=0;
            for(int b:nums){
                if(a==b)cnt++;
            }
            if(cnt==1)ans+=a;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,2,3,2};
    auto ans=sol.sumOfUnique(nums);
    DBG(ans);

    system("pause");
    return 0;
}
