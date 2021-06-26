#include "EulerPrime.h"
#include "utils.h"

class Solution {
public:
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        static EulerPrime<200001>ep;
        int Max=*max_element(ALL(nums));
        int gcd_of_multiple[Max+1];
        memset(gcd_of_multiple,0,sizeof(gcd_of_multiple));
        for(int a:nums){
            ep.getFactors(a);
            REP(_,ep.flen){
                int f=ep.factors[_];
                if(!gcd_of_multiple[f])gcd_of_multiple[f]=a;
                else gcd_of_multiple[f]=mygcd(gcd_of_multiple[f],a);
            }
        }
        int ans=0;
        FOR(i,1,Max+1){
            if(gcd_of_multiple[i]==i){
                ans++;
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{6,10,3};
    auto ans=sol.countDifferentSubsequenceGCDs(nums);
    DBG(ans);

    system("pause");
    return 0;
}
