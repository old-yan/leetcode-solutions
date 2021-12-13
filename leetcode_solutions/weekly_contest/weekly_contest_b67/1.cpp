#include "utils.h"

class Solution {
public:
    //本题显然需要两次排序：
    //  第一次排序看谁的值大，值最大的 k 个留下
    //  第二次排序看下标，按下标顺序排好
    //那么，要想保留下标和值两个信息，可以用 pair
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        //第一次排序，找出值最大的 k 个
        priority_queue<pair<int,int>>Q;
        for(int i=0;i<nums.size();i++)
            Q.emplace(nums[i],i);
        vector<int>ans;
        //将值最大的 k 个下标放到 ans 里
        while(ans.size()<k){
            ans.push_back(Q.top().second);
            Q.pop();
        }
        //将下标排序，然后恢复成各自的值
        sort(ans.begin(),ans.end());
        for(int &a:ans)a=nums[a];
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<int>nums{2,1,3,3};
    int k=2;
    auto ans=sol.maxSubsequence(nums,k);
    DBGV(ans);

    system("pause");
    return 0;
}