#include "utils.h"

class Solution {
public:
    int minCharacters(string a, string b) {
        int cnt1[26]={0},cnt2[26]={0};
        for(char c:a)cnt1[c-'a']++;
        for(char c:b)cnt2[c-'a']++;
        int ans=INT_MAX;
        REP(i,25){
            int need=accumulate(cnt1+i+1,cnt1+26,0)+accumulate(cnt2,cnt2+i+1,0);
            chmin(ans,need);
        }
        REP(i,25){
            int need=accumulate(cnt2+i+1,cnt2+26,0)+accumulate(cnt1,cnt1+i+1,0);
            chmin(ans,need);
        }
        REP(i,26){
            int need=a.size()+b.size()-cnt1[i]-cnt2[i];
            chmin(ans,need);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string a="aba";
    string b="caa";
    auto ans=sol.minCharacters(a,b);
    DBG(ans);

    system("pause");
    return 0;
}
