#include "utils.h"

class Solution {
public:
    int countHomogenous(string s) {
        //使用next_different函数将s划分为多个同字符区间
        vi next=next_different(s);
        int ans=0;
        for(int i=0;i<s.size();i=next[i]){
            //比如从下标i到下标next[i]，有连续的j个相同字符'#'
            ll j=next[i]-i;
            //那么有j个长为1子串，j-1个长为2子串，j-2个长为3子串，...，1个长为j子串
            //共有j*(j+1)/2个子串
            ans=(ans+j*(j+1)/2)%MOD;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="abbcccaa";
    auto ans=sol.countHomogenous(s);
    DBG(ans);

    system("pause");
    return 0;
}
