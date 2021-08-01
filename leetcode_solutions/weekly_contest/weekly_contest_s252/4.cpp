#include "utils.h"

class Solution {
public:
    //简单的动态规划，从每个位置的方案数，推出下个位置的方案数
    int countSpecialSubsequences(vector<int>& nums) {
        //No表示什么都没有的方案数
        //Zero表示目前只有零的方案数
        //Zeroone表示零取够了，现在正在取一的方案数
        //Zeroonetwo表示零和一取够了，现在正在取二的方案数
        long long No=1,Zero=0,Zeroone=0,Zeroonetwo=0;
        for(int a:nums){
            Zeroonetwo=(Zeroonetwo+(Zeroone+Zeroonetwo)*(a==2))%MOD;
            Zeroone=(Zeroone+(Zeroone+Zero)*(a==1))%MOD;
            Zero=(Zero+(No+Zero)*(a==0))%MOD;
            No=No;
        }
        return Zeroonetwo;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{0,1,2,0,1,2};
    auto ans=sol.countSpecialSubsequences(nums);
    DBG(ans);

    system("pause");
    return 0;
}
