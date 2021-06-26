#include "utils.h"

class Solution {
public:
    //本题数据量较小，可以n2暴力，当然最好还是学会线性求法
    bool canBeIncreasing(vector<int>& nums) {
        //l指向从前往后递增的最终位置
        //r指向从后往前递减的最前位置
        int l,r;
        for(l=0;l+1<nums.size()&&nums[l+1]>nums[l];l++);
        for(r=nums.size()-1;r-1>=0&&nums[r-1]<nums[r];r--);
        //如果区间距离太远（大于2），那么删一个是不够的。
        if(r-l>2)return false;
        //如果距离为2，中间隔着一个元素，可以试试删掉它
        if(r-l==2)return nums[r]>nums[l];
        //如果距离为0（甚至为负，也就是互有交织）,那不用删就成了
        if(l>=r)return true;
        //如果距离为1，可以考虑删除nums[l] 或者 nums[r]
        if(l==0||r==nums.size()-1)return true;
        if(nums[r]>nums[l-1]||nums[r+1]>nums[l])return true;
        return false;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,2,10,5,7};
    auto ans=sol.canBeIncreasing(nums);
    DBG(ans);

    system("pause");
    return 0;
}
