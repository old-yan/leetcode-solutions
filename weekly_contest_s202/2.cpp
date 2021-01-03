#include "utils.h"

class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        //M用来记录之前出现过的数的出现次数
        unordered_map<int,int>M;
        ll ans=0;
        for(int a:deliciousness){
            //sum遍历从1到2^21之间的2的幂
            for(int sum=1;sum<=(1<<21);sum<<=1){
                if(a<=sum){
                    ans=(ans+M[sum-a])%MOD;
                }
            }
            M[a]++;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi deliciousness{1,1,1,3,3,3,7};
    auto ans=sol.countPairs(deliciousness);
    DBG(ans);

    system("pause");
    return 0;
}
