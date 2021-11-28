#include "utils.h"

class Solution {
public:
    //两个极值将数组分成三段，我们可以枚举将这三段的某一段保留的情况，选取最佳
    int minimumDeletions(vector<int>& nums) {
        if(nums.size()==1)return 1;
        int index1=min_element(nums.begin(),nums.end())-nums.begin();
        int index2=max_element(nums.begin(),nums.end())-nums.begin();
        if(index1>index2)swap(index1,index2);
        int n=nums.size();
        return min({n-index1,n-(index2-index1-1),index2+1});
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<int>nums{2,10,7,5,4,1,8,6};
    auto ans=sol.minimumDeletions(nums);
    DBG(ans);

    system("pause");
    return 0;
}