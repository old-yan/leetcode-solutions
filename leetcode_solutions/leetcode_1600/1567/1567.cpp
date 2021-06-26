#include "utils.h"

class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        ll pos=-1,neg=0x3f3f3f3f,ans=0,prod=1;
        REP(i,nums.size()){
            if(!nums[i]){
                prod=1;
                pos=i;
                neg=0x3f3f3f3f;
            }
            else{
                prod*=nums[i];
                if(prod>0){
                    prod=1;
                    chmax(ans,i-pos);
                }
                else{
                    prod=-1;
                    chmax(ans,i-neg);
                    chmin(neg,i);
                }
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,-2,-3,4};
    auto ans=sol.getMaxLen(nums);
    DBG(ans);

    system("pause");
    return 0;
}
