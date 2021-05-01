#include "utils.h"

class Solution {
    int init(vi&nums){
        int ret=0;
        FOR(i,1,nums.size()){
            ret+=abs(nums[i]-nums[i-1]);
        }
        return ret;
    }
public:
    int maxValueAfterReverse(vector<int>& nums) {
        int n=nums.size();
        int ret=init(nums);
        int ans=ret;
        REP(i,n-1){
            chmax(ans,ret-abs(nums[i+1]-nums[i])+abs(nums[i+1]-nums[0]));
            chmax(ans,ret-abs(nums[i]-nums[i+1])+abs(nums[i]-nums.back()));
        }
        vi minMax(n),maxMin(n);
        minMax[n-1]=INT_MAX,maxMin[n-1]=INT_MIN;
        REPR(i,n-2){
            minMax[i]=min(minMax[i+1],max(nums[i],nums[i+1]));
            maxMin[i]=max(maxMin[i+1],min(nums[i],nums[i+1]));
        }
        REP(i,n-1){
            int a=max(nums[i],nums[i+1]),b=min(nums[i],nums[i+1]);
            if(maxMin[i]>a)chmax(ans,ret+(maxMin[i]-a)*2);
            if(minMax[i]<b)chmax(ans,ret+(b-minMax[i])*2);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{2,3,1,5,4};
    auto ans=sol.maxValueAfterReverse(nums);
    DBG(ans);

    system("pause");
    return 0;
}
