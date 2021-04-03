#include "utils.h"

class Solution {
public:
    int distinctSubseqII(string S) {
        int cnt[26]={0};
        int ans=1;
        for(char c:S){
            int inc=(ans+MOD-cnt[c-'a'])%MOD;
            cnt[c-'a']=(cnt[c-'a']+inc)%MOD;
            ans=(ans+inc)%MOD;
        }
        return ans-1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string S="abc";
    auto ans=sol.distinctSubseqII(S);
    DBG(ans);

    system("pause");
    return 0;
}
