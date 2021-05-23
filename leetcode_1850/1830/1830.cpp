#include "utils.h"

class Solution {
public:
    int makeStringSorted(string s) {
        int n=s.size();
        int cnt[26]={0};
        ll comb=1,ans=0;
        REPR(i,n-1){
            int cur=s[i]-'a';
            cnt[cur]++;
            comb=comb*(n-i)%MOD*inv(cnt[cur])%MOD;
            REP(j,cur)if(cnt[j]){
                ans=(ans+comb*inv(n-i)%MOD*cnt[j])%MOD;
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="cba";
    auto ans=sol.makeStringSorted(s);
    DBG(ans);

    system("pause");
    return 0;
}
