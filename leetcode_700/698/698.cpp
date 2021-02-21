#include "utils.h"

class Solution {
    int sum[1<<16]={0};
    bool can[1<<16]={0};
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int total=accumulate(ALL(nums),0);
        if(total%k)return false;
        int every=total/k;
        int Max=*max_element(ALL(nums));
        if(Max>every)return false;
        for(int i=1;i<(1<<nums.size());i++){
            int j=__builtin_ctz(i);
            sum[i]=sum[i-(1<<j)]+nums[j];
            if(sum[i]%every==0){
                if(sum[i]==every)can[i]=true;
                else{
                    for(int s=i;__builtin_clz(s)==__builtin_clz(i);s=(s-1)&i){
                        if(can[s]&&can[i-s]){
                            can[i]=true;
                            break;
                        }
                    }
                }
            }
        }
        return can[(1<<nums.size())-1];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{4, 3, 2, 3, 5, 2, 1};
    int k=4;
    auto ans=sol.canPartitionKSubsets(nums,k);
    DBG(ans);

    system("pause");
    return 0;
}
