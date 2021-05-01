#include "utils.h"

class Solution {
public:
    bool canConstruct(string s, int k) {
        int cnt[26]={0};
        for(char c:s)cnt[c-'a']++;
        int odd=0;
        REP(i,26)if(cnt[i]%2)odd++;
        return odd<=k&&s.size()>=k;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="annabelle";
    int k=2;
    auto ans=sol.canConstruct(s,k);
    DBG(ans);

    system("pause");
    return 0;
}
