#include "Trie.h"
#include "utils.h"

StaticTrie T;
class Solution {
public:
    int respace(vector<string>& dictionary, string sentence) {
        T.clear();
        for(auto&s:dictionary)
            T.insert(s);
        int n=sentence.size();
        int dp[n+1];
        dp[n]=0;
        REPR(i,n-1){
            dp[i]=n-i;
            int cur=0;
            FOR(j,i,n){
                cur=T[cur][sentence[j]-'a'];
                if(!cur){
                    while(j<n)chmin(dp[i],dp[j+1]+int(j-i+1)),j++;
                    break;
                }
                if(T[cur][26]>=0)chmin(dp[i],dp[j+1]);
                else chmin(dp[i],dp[j+1]+int(j-i+1));
            }
        }
        return dp[0];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<string>dictionary{
        "looked","just","like","her","brother"
    };
    string sentence="jesslookedjustliketimherbrother";
    auto ans=sol.respace(dictionary,sentence);
    DBG(ans);

    system("pause");
    return 0;
}
