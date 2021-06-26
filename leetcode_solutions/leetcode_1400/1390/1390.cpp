#include "EulerPrime.h"
#include "utils.h"

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        static EulerPrime<100000>ep;
        int ans=0;
        for(int a:nums){
            ep.getFactors(a);
            if(ep.flen==4){
                ans+=accumulate(ep.factors,ep.factors+4,0);
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{21,4,7};
    auto ans=sol.sumFourDivisors(nums);
    DBG(ans);

    system("pause");
    return 0;
}
