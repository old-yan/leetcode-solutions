#include "utils.h"

class Solution {
public:
    vector<vector<int>> pairSums(vector<int>& nums, int target) {
        unordered_map<int,int>M;
        vvi ans;
        for(int a:nums){
            int b=target-a;
            if(M.count(b)){
                if(!--M[b])M.erase(b);
                ans.pb({b,a});
            }
            else M[a]++;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{5,6,5};
    int target=11;
    auto ans=sol.pairSums(nums,target);
    DBGVV(ans);

    system("pause");
    return 0;
}
