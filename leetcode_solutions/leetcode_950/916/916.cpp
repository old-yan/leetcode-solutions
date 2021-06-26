#include "utils.h"

class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        int need[26]={0};
        for(auto&s:B){
            int cnt[26]={0};
            for(char c:s)cnt[c-'a']++;
            REP(i,26)chmax(need[i],cnt[i]);
        }
        vector<string>ans;
        for(auto&s:A){
            int cnt[26]={0};
            for(char c:s)cnt[c-'a']++;
            bool b=true;
            REP(i,26)if(need[i]>cnt[i])b=false;
            if(b)ans.pb(s);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<string>A{"amazon","apple","facebook","google","leetcode"};
    vector<string>B{"o","e"};
    auto ans=sol.wordSubsets(A,B);
    DBGV(ans);

    system("pause");
    return 0;
}
