#include "utils.h"

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        zkwTree T(nums.size());
        vi rank=getrank2(nums);
        vi ans(nums.size(),0);
        REPR(i,rank.size()-1){
            int j=rank[i];
            if(j)ans[i]=T(0,j-1);
            T.set(j,T[j]+1);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{5,2,6,1};
    auto ans=sol.countSmaller(nums);
    DBGV(ans);

    system("pause");
    return 0;
}
