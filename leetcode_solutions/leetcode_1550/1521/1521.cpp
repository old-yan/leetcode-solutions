#include "utils.h"

class Solution {
public:
    int closestToTarget(vector<int>& arr, int target) {
        int ans=abs(-1000000000-target);
        int cnt[32]={0};
        for(int left=0,right=0;right<arr.size();right++){
            int sum=0;
            REP(i,32){
                cnt[i]+=arr[right]>>i&1;
                if(cnt[i]==right-left+1)sum|=1<<i;
            }
            chmin(ans,abs(sum-target));
            while(left<right&&sum<target){
                sum=0;
                REP(i,32){
                    cnt[i]-=arr[left]>>i&1;
                    if(cnt[i]==right-left)sum|=1<<i;
                }
                left++;
                chmin(ans,abs(sum-target));
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi arr{9,12,3,7,15};
    int target=5;
    auto ans=sol.closestToTarget(arr,target);
    DBG(ans);

    system("pause");
    return 0;
}
