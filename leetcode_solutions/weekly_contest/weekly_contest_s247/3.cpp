#include "utils.h"

class Solution {
public:
    //本题需要使用前缀和思想和状态压缩
    //状态压缩：用二进制的末尾十位，表示a~j的数量的奇偶性，通过异或进行累加，某位为1表示现在有奇数个，某位为0表示现在有偶数个
    //前缀和：前缀和做差，快速求出某段区间的
    long long wonderfulSubstrings(string word) {
        //dp[state]表示前缀和为state的位置数量
        int dp[1024]={0};
        ll ans=0;
        int cur=0;
        dp[cur]++;
        for(char _c:word){
            int c=_c-'a';
            //cur表示当前前缀和
            cur^=1<<c;
            //出现奇数次的字符数为0
            ans+=dp[cur];
            for(int i=0;i<10;i++){
                //出现奇数次的字符数为1
                ans+=dp[cur^(1<<i)];
            }
            dp[cur]++;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string word="aabb";
    auto ans=sol.wonderfulSubstrings(word);
    DBG(ans);

    system("pause");
    return 0;
}
