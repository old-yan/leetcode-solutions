#include "utils.h"

class Solution {
public:
    int minSteps(string s, string t) {
        int cnt[26]={0};
        for(char c:s)cnt[c-'a']++;
        for(char c:t)cnt[c-'a']--;
        int ans=0;
        REP(i,26)if(cnt[i]>0)ans+=cnt[i];
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="friend";
    string t="family";
    auto ans=sol.minSteps(s,t);
    DBG(ans);

    system("pause");
    return 0;
}
