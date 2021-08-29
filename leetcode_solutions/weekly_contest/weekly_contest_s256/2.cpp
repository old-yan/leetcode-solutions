#include "utils.h"

class Solution {
public:
    //本题考查排序规则
    //对于没有前导零的大数字，首先根据位数来排序，位数相等则按字典序排序
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(),nums.end(),[](string&x,string&y){
            if(x.size()!=y.size())return x.size()<y.size();
            else return x<y;
        });
        return nums[nums.size()-k];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<string>nums{"2","21","12","1"};
    int k=3;
    auto ans=sol.kthLargestNumber(nums,k);
    DBG(ans);

    system("pause");
    return 0;
}
