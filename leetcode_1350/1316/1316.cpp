#include "Trie.h"
#include "utils.h"

int dp[2000][2001];
class mytrie:public StaticTrie{
public:
    mytrie():StaticTrie(){}
    void insert(const string&word,int i){
        int cur=0;
        FOR(j,i,word.size()){
            if(!data[cur][word[j]-'a'])Malloc(data[cur][word[j]-'a']);
            cur=data[cur][word[j]-'a'];
            if(data[cur][26]>=0)dp[i][j-i+1]=data[cur][26];
            else dp[i][j-i+1]=data[cur][26]=i;
        }
    }
};

mytrie T;
class Solution {
public:
    int distinctEchoSubstrings(string text) {
        int n=text.size();
        int ans=0;
        memset(dp,0xff,sizeof(dp));
        T.clear();
        REP(i,n)T.insert(text,i);
        for(int len=2;len<=n;len+=2){
            bool used[n];
            memset(used,0,sizeof(used));
            for(int i=0;i<=n-len*2;i++){
                if(dp[i][len]==dp[i+len][len]){
                    if(!used[dp[i][len*2]]){
                        used[dp[i][len*2]]=true;
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};



int main()
{
    cout<<boolalpha;
    Solution sol;

    string text="leetcodeleetcode";
    auto ans=sol.distinctEchoSubstrings(text);
    DBG(ans);

    system("pause");
    return 0;
}
