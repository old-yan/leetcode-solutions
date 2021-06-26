#include "utils.h"

class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        auto sum=accumulate(ALL(nums),0,[](int x,int y){return x^y;});
        int A=0,B=0;
        for(int a:nums){
            if(a&(sum&(-sum)))A^=a;
            else B^=a;
        }
        return {A,B};
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{4,1,4,6};
    auto ans=sol.singleNumbers(nums);
    DBGV(ans);

    system("pause");
    return 0;
}
