#include "StringHasher.h"
#include "utils.h"

class Solution {
public:
    int maxRepeating(string sequence, string word) {
        StringHasher s(sequence),t(word);
        ll pat=t.ask(0,word.size()-1);
        int dp[sequence.size()];
        memset(dp,0,sizeof(dp));
        REP(i,sequence.size()){
            if(i+word.size()>sequence.size())break;
            ll cur=s.ask(i,i+word.size()-1);
            if(cur==pat)dp[i]=i>=word.size()?dp[i-word.size()]+1:1;
            else dp[i]=0;
        }
        return *max_element(dp,dp+sequence.size());
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string sequence="ababc";
    string word="ab";
    auto ans=sol.maxRepeating(sequence,word);
    DBG(ans);

    system("pause");
    return 0;
}
