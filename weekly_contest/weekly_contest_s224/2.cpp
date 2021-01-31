#include "utils.h"

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,int>M;
        int n=nums.size();
        //两重for循环，求出每种乘积的对数
        REP(i,n){
            REP(j,i){
                M[nums[i]*nums[j]]++;
            }
        }
        //对于每种乘积，可以产生C(2,m)种匹配对
        //每种匹配对可以产生8种排列
        int ans=0;
        for(auto&it:M){
            int i=it.second;
            if(i>1){
                ans+=i*(i-1)/2*8;
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{2,3,4,6};
    auto ans=sol.tupleSameProduct(nums);
    DBG(ans);

    system("pause");
    return 0;
}
