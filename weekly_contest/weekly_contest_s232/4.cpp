#include "utils.h"

class Solution {
public:
    //贪心思考，令区域最小值逐渐增大，则区间逐渐变小，在变化过程中寻找最优解
    int maximumScore(vector<int>& nums, int k) {
        vi indexes[20001];
        int n=nums.size();
        //先将所有下标按照对应的值放到数组里
        for(int i=0;i<n;i++){
            indexes[nums[i]].pb(i);
        }
        //维护区间范围，一开始区域最小值为1，那么左边界为0，右边界为n-1
        int left=0,right=n-1;
        int ans=0;
        for(int Min=1;Min<=nums[k];Min++){
            if(indexes[Min].size()){
                ans=max(ans,(right-left+1)*Min);
            }
            //提高Min之后，需要缩小边界
            for(int idx:indexes[Min]){
                if(idx<k){
                    left=max(left,idx+1);
                }
                else if(idx>k){
                    right=min(right,idx-1);
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

    vi nums{5,5,4,5,4,1,1,1};
    int k=0;
    auto ans=sol.maximumScore(nums,k);
    DBG(ans);

    system("pause");
    return 0;
}
