#include "utils.h"

class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        //求出前缀和数组
        partial_sum(ALL(nums),nums.begin());
        int total=nums.back();
        //三个指针(按照从1开始到n，而非从0开始到n-1)
        //第一个指针i是左区间的尾坐标
        //第二个指针j是中区间的尾坐标，最左能取哪里
        //第三个指针k是右区间的头坐标，最右能取哪里
        int ans=0;
        for(int i=0,j=1,k=1;i<nums.size()-2&&nums[i]<=total/3;i++){
            int left_sum=nums[i];
            //middle_sum必须处于left_sum*2到left_sum+(total-left_sum)/2之间
            while(j==i||(nums[j]<left_sum*2)){
                j++;
            }
            while(k+1<nums.size()&&nums[k]<=left_sum+(total-left_sum)/2){
                k++;
            }
            //中区间的尾巴可以取j~k-1之间的值
            ans=(ans+k-j)%MOD;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,2,2,2,5,0};
    auto ans=sol.waysToSplit(nums);
    DBG(ans);

    system("pause");
    return 0;
}
