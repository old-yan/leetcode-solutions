#include "utils.h"

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string>v(nums.size());
        REP(i,nums.size())v[i]=i2s(nums[i]);
        vi idx(nums.size());
        iota(ALL(idx),0);
        sort(ALL(idx),[&](int x,int y)->bool{return v[x]+v[y]>v[y]+v[x];});
        string ans;
        REP(i,nums.size()){
            ans+=v[idx[i]];
        }
        if(ans[0]=='0')return "0";
        else return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{3,30,34,5,9};
    auto ans=sol.largestNumber(nums);
    DBG(ans);

    system("pause");
    return 0;
}
