#include "EulerPrime.h"
#include "utils.h"

class Solution {
    int gcd_of_multiples[200001]={0};
public:
    //本题可以遍历每一个数的所有因数，看看这个因数能否成为一个最大公约数
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        static EulerPrime<200000>ep;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                gcd_of_multiples[1]=1;
            }
            else{
                //ep辅助获取nums[i]的所有的因数
                ep.getFactors(nums[i]);
                REP(_,ep.flen){
                    int a=ep.factors[_];
                    if(gcd_of_multiples[a]){
                        gcd_of_multiples[a]=gcd(gcd_of_multiples[a],nums[i]);
                    }
                    else gcd_of_multiples[a]=nums[i];
                }
            }
        }
        //对所有可以成为gcd的数进行累加
        int ans=0;
        for(int i=1;i<=200000;i++){
            ans+=gcd_of_multiples[i]==i;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{13,7,4,16,1};
    auto ans=sol.countDifferentSubsequenceGCDs(nums);
    DBG(ans);

    system("pause");
    return 0;
}



//  5   15  40  5   6
//  5
//  5   15
//  5   15  40
//  5   15  40
//  1   2   3   5   6   15  40
//  2*3*5*7*11*13*17