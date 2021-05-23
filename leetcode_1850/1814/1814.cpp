#include "utils.h"

class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>M;
        ll ans=0;
        REP(i,n){
            int a=nums[i],b=0;
            while(a){
                b=b*10+a%10;
                a/=10;
            }
            b-=nums[i];
            ans+=M[b]++;
        }
        return ans%MOD;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{42,11,1,97};
    auto ans=sol.countNicePairs(nums);
    DBG(ans);

    system("pause");
    return 0;
}
