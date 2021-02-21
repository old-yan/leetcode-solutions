#include "utils.h"

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vi rnk=getrank2(nums);
        SegTree<int>T(rnk.size(),0,[](int x,int y){
            return max(x,y);
        });
        for(int a:rnk){
            T.set(a,T(0,a-1)+1);
        }
        return T.data[1];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{11,12,13,14,15,6,7,8,101,18};
    auto ans=sol.lengthOfLIS(nums);
    DBG(ans);

    system("pause");
    return 0;
}
