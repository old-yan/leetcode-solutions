#include "utils.h"

class Solution {
public:
    //本题一看数据范围，首先考虑状态压缩，用n位长的二进制数字表示对每个字符进行取舍后留下的子序列字符串
    int maxProduct(string s) {
        int n=s.size();
        //首先对每个状态表示的子序列字符串进行对称判断
        vector<bool>isP(1<<n,false);
        for(int state=0;state<1<<n;state++){
            string sub;
            for(int i=0;i<n;i++)if(state>>i&1){
                sub+=s[i];
            }
            isP[state]=isPalindromic(ALL(sub));
        }
        //然后枚举一个子序列，在其补集内进行枚举子集作为第二个子序列。这样可以保证两个子序列不相交
        int ans=0;
        for(int first=0;first<1<<n;first++)if(isP[first]){
            int rest=(1<<n)-1-first;
            for(int second=rest;second;second=(second-1)&rest)if(isP[second]){
                chmax(ans,__builtin_popcount(first)*__builtin_popcount(second));
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="leetcodecom";
    auto ans=sol.maxProduct(s);
    DBG(ans);

    system("pause");
    return 0;
}