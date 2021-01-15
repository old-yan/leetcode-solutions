#include "utils.h"

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=nums.size();
        vi Minbefore(n);
        REP(i,n)Minbefore[i]=i?min(Minbefore[i-1],nums[i-1]):INT_MAX;
        vi smaller(n);
        set<int,greater<int>>S;
        REPR(i,n-1){
            auto find=S.lower_bound(nums[i]-1);
            if(find==S.end())smaller[i]=INT_MIN;
            else smaller[i]=*find;
            S.insert(nums[i]);
        }
        FOR(i,1,n-1){
            if(smaller[i]>Minbefore[i])return true;
        }
        return false;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{3,1,4,2};
    auto ans=sol.find132pattern(nums);
    DBG(ans);

    system("pause");
    return 0;
}
