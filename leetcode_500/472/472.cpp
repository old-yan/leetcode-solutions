#include "utils.h"

class Solution {
    typedef DynamicTrie Trie;
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        Trie T;
        sort(ALL(words),[&](string&x,string&y)->bool{return x.size()<y.size();});
        vector<string>ans;
        for(string&s:words){
            if(s.empty())continue;
            bool dp[s.size()+1];
            memset(dp,0,sizeof(dp));
            dp[s.size()]=1;
            REPR(i,s.size()-1){
                auto p=T.child[s[i]-'a'];
                FOR(j,i+1,s.size()+1){
                    if(!p)break;
                    if(p->signal>=0&&dp[j]){
                        dp[i]=true;
                        break;
                    }
                    if(j==s.size())break;
                    p=p->child[s[j]-'a'];
                }
            }
            T.insert(s);
            if(dp[0])ans.pb(s);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<string>words{
        "cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"
    };
    auto ans=sol.findAllConcatenatedWordsInADict(words);
    DBGV(ans);

    system("pause");
    return 0;
}
