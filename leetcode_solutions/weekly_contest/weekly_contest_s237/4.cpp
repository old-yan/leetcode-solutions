#include "utils.h"

class Solution {
public:
    //按位与的意思就是，你有我有那才有。而且每位是独立不相关的，所以我们每位都独立处理
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int n1=arr1.size(),n2=arr2.size();
        ll cnt1[32]={0},cnt2[32]={0},res[32]={0};
        //统计每一位上arr1的1的个数
        for(int a:arr1){
            REP(i,32){
                if(a>>i&1)cnt1[i]++;
            }
        }
        //统计每一位上arr2的1的个数
        for(int a:arr2){
            REP(i,32){
                if(a>>i&1)cnt2[i]++;
            }
        }
        //arr1的每个数的每个位在and结果中的出现次数，取决于arr2的相应位的出现次数
        for(int a:arr1){
            REP(i,32)if(a>>i&1){
                res[i]+=cnt2[i];
            }
        }
        //arr2的每个数的每个位在and结果中的出现次数，取决于arr1的相应位的出现次数
        for(int a:arr2){
            REP(i,32)if(a>>i&1){
                res[i]+=cnt1[i];
            }
        }
        int ans=0;
        //首先记得要除以2，因为一个and值我们统计了两边
        //其次，异或就是两两相消，所以看除以2的余数判断这一位异或的结果
        REP(i,32){
            if(res[i]/2%2)ans|=(1<<i);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi arr1{1,2,3};
    vi arr2{6,5};
    auto ans=sol.getXORSum(arr1,arr2);
    DBG(ans);

    system("pause");
    return 0;
}
