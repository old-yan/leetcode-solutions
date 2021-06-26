#include "utils.h"

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>M;
        for(int a:nums)M[a]++;
        sort(ALL(nums),[&](int x,int y){
            if(M[x]!=M[y])return M[x]<M[y];
            else return x>y;
        });
        return nums;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,1,2,2,2,3};
    auto ans=sol.frequencySort(nums);
    DBGV(ans);

    system("pause");
    return 0;
}
