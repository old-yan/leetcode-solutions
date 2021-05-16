#include "utils.h"

class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vi ans;
        int cursor=0,n=nums.size();
        REP(i,k){
            while(n-cursor+i>k){
                while(ans.size()>i&&ans.back()>nums[cursor])ans.pop_back();
                ans.pb(nums[cursor++]);
            }
            if(ans.size()==i||(cursor<n&&nums[cursor]<ans[i])){
                ans.erase(ans.begin()+i,ans.end());
                ans.insert(ans.end(),nums.begin()+cursor,nums.end());
                break;
            }
        }
        ans.resize(k);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{71,18,52,29,55,73,24,42,66,8,80,2};
    int k=3;
    auto ans=sol.mostCompetitive(nums,k);
    DBGV(ans);

    system("pause");
    return 0;
}
