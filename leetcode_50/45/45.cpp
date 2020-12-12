#include "utils.h"

class Solution {
public:
    int jump(vector<int>& nums) {
        int step=0,limit=0,maxdis=0;
        REP(i,nums.size()-1){
            chmax(maxdis,int(i+nums[i]));
            if(i==limit){
                step++;
                limit=maxdis;
            }
        }
        return step;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{2,3,1,1,4};
    auto ans=sol.jump(nums);
    DBG(ans);

    system("pause");
    return 0;
}