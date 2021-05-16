#include "utils.h"

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool>ans(l.size(),true);
        REP(i,l.size()){
            int left=l[i],right=r[i];
            int tmp[right-left+1];
            memcpy(tmp,&nums[left],(right-left+1)*sizeof(int));
            sort(tmp,tmp+(right-left+1));
            int d=tmp[1]-tmp[0];
            FOR(j,2,right-left+1){
                if(tmp[j]!=tmp[j-1]+d){
                    ans[i]=false;
                    break;
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

    vi nums{4,6,5,9,3,7};
    vi l{0,0,2};
    vi r{2,3,5};
    auto ans=sol.checkArithmeticSubarrays(nums,l,r);
    DBGV(ans);

    system("pause");
    return 0;
}
