#include "utils.h"

class Solution {
    int n;
    string ans;
    void dfs(string cur,vector<string>&nums){
        if(cur.size()==n){
            //如果在nums中出现，就不行
            for(string&s:nums)if(cur==s){
                return;
            }
            //如果没有在nums中出现，就行
            ans=cur;
        }
        else{
            dfs(cur+"0",nums);
            //记得剪枝
            if(ans.size())return;
            dfs(cur+"1",nums);
        }
    }
public:
    //数据范围很小，dfs就可以
    //注意没必要遍历所有可能，能找到一个解就赶紧返回
    string findDifferentBinaryString(vector<string>& nums) {
        n=nums.size();
        dfs("",nums);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<string>nums{"111","011","001"};
    auto ans=sol.findDifferentBinaryString(nums);
    DBG(ans);

    system("pause");
    return 0;
}
