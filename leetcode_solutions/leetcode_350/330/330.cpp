#include "utils.h"

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        ll lost=1;
        int ans=0;
        for(int a:nums){
            if(a>n)break;
            while(a>lost){
                ans++;
                lost<<=1;
            }
            lost+=a;
        }
        while(lost<=n){
            ans++;
            lost<<=1;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,5,10};
    int n=20;
    auto ans=sol.minPatches(nums,n);
    DBG(ans);

    system("pause");
    return 0;
}
