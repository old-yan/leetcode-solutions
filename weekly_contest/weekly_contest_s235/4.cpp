#include "EulerPrime.h"
#include "utils.h"

class Solution {
    int gcd_of_multiples[200001]={0};
    void dfs(vi&factors,vi&next,int cur,ll curp,int a){
        if(cur==next.size()){
            if(gcd_of_multiples[curp]){
                gcd_of_multiples[curp]=gcd(gcd_of_multiples[curp],a);
            }
            else gcd_of_multiples[curp]=a;
        }
        else{
            int j=next[cur]-cur;
            for(int i=0;i<=j;i++){
                dfs(factors,next,next[cur],curp,a);
                curp*=factors[cur];
            }
        }
    }
public:
    //本题可以遍历每一个数的所有因数，看看这个因数能否成为一个最大公约数
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        static EulerPrime<1000000>ep;
        int ans=0;
        //排序减少一些重复操作
        sort(ALL(nums));
        int Max=nums.back();
        for(int i=0,j;i<nums.size();i=j){
            if(nums[i]==1){
                gcd_of_multiples[1]=1;
            }
            else{
                //先进行质因数分解
                auto factors=ep.getFactors<1>(nums[i]);
                auto next=next_different(factors);
                //dfs获取所有可能的质因数组合，也就是获取所有的因数
                dfs(factors,next,0,1,nums[i]);
            }
            for(j=i+1;j<nums.size()&&nums[j]==nums[i];j++);
        }
        //对所有可以成为gcd的数进行累加
        for(int i=1;i<=Max;i++){
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