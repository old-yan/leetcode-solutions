#include "utils.h"

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        int cnt[26];
        fill(cnt,cnt+26,INT_MAX);
        for(string&s:A){
            int cur[26]={0};
            for(char c:s)cur[c-'a']++;
            REP(i,26)chmin(cnt[i],cur[i]);
        }
        vector<string>ans;
        REP(i,26){
            while(cnt[i]--){
                ans.emplace_back(1,'a'+i);
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<string>A{"bella","label","roller"};
    auto ans=sol.commonChars(A);
    DBGV(ans);

    system("pause");
    return 0;
}
