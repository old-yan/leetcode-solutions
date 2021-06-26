#include "utils.h"

class Solution {
public:
    //本题可以使用next_permutation获取“下一个排列”，也就是比当前值刚好大一个顺次的字符串
    int getMinSwaps(string num, int k) {
        string copy=num;
        //连续调用k次next_permutation
        while(k--)next_permutation(ALL(copy));
        int ans=0;
        for(int i=0;i<copy.size();i++){
            //要想通过swap操作将num变成copy
            //我们必须找到第一个满足num[idx]==copy[i]的资源
            //然后不远万里把它挪过来
            int idx=num.find(copy[i],i);
            ans+=idx-i;
            //目标字符挪到前头来了，那么中间路上的字符就得往后腾一个位置
            FORR(j,idx-1,i){
                num[j+1]=num[j];
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string num="5489355142";
    int k=4;
    auto ans=sol.getMinSwaps(num,k);
    DBG(ans);

    system("pause");
    return 0;
}
