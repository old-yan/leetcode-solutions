#include "utils.h"

class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector<string>strs;
        for(int a:nums)strs.pb(i2s(a));
        sort(ALL(strs),[](string&x,string&y){return x+y<y+x;});
        string ans;
        for(string&a:strs)ans+=a;
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{3,30,34,5,9};
    auto ans=sol.minNumber(nums);
    DBG(ans);

    system("pause");
    return 0;
}
