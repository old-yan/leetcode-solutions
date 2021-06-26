#include "utils.h"

class Solution {
public:
    int findLHS(vector<int>& nums) {
        int ans=0;
        map<int,int>M;
        for(int a:nums){
            M[a]++;
        }
        for(auto&it:M){
            if(M.count(it.first-1))chmax(ans,it.second+M[it.first-1]);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,3,2,2,5,2,3,7};
    auto ans=sol.findLHS(nums);
    DBG(ans);

    system("pause");
    return 0;
}
