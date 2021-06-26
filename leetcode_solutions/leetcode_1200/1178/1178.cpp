#include "utils.h"

int dp[1<<26];
class Solution {
    vi masks;
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        for(string&s:words){
            int mask=0;
            for(char c:s)mask|=1<<(c-'a');
            masks.pb(mask);
            dp[mask]++;
        }
        vi ans;
        for(string&s:puzzles){
            int mask=0;
            for(char c:s)mask|=1<<(c-'a');
            int key=1<<(s[0]-'a');
            mask-=key;
            int cnt=dp[key];
            for(int sub=mask;sub;sub=(sub-1)&mask){
                cnt+=dp[sub|key];
            }
            ans.pb(cnt);
        }
        for(int mask:masks){
            dp[mask]=0;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<string>words{
        "aaaa","asas","able","ability","actt","actor","access"
    };
    vector<string>puzzles{
        "aboveyz","abrodyz","abslute","absoryz","actresz","gaswxyz"
    };
    auto ans=sol.findNumOfValidWords(words,puzzles);
    DBGV(ans);

    system("pause");
    return 0;
}
