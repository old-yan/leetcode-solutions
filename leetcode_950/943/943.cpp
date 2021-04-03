#include "utils.h"

class Solution {
    int n;
    int dis[12][12];
    vi next[12];
    int dp[1<<12][12];
    string ans;
    int getlen(string&s1,string&s2,vi&next){
        int i=max(0,int(s1.size()-s2.size())),j=0;
        while(i<s1.size()){
            if(j<0||s1[i]==s2[j]){i++,j++;}
            else j=next[j];
        }
        return i-j;
    }
    void dfs(int state,int start,int len,vector<string>&words){
        state-=1<<start;
        if(!state)ans+=words[start];
        else{
            for(int i=0;i<n;i++){
                if(state>>i&1){
                    if(dp[state][i]==len-dis[start][i]){
                        ans+=words[start].substr(0,dis[start][i]);
                        dfs(state,i,dp[state][i],words);
                        return;
                    }
                }
            }
        }
    }
public:
    string shortestSuperstring(vector<string>& words) {
        n=words.size();
        REP(i,n)next[i]=getnext(words[i]);
        REP(i,n){
            REP(j,n){
                dis[i][j]=getlen(words[i],words[j],next[j]);
            }
        }
        memset(dp,0x3f,sizeof(dp));
        FOR(state,1,1<<n){
            bitset<32>b(state);
            for(int i=b._Find_first();i<32;i=b._Find_next(i)){
                b.reset(i);
                if(!b.count())dp[state][i]=words[i].size();
                else{
                    for(int j=b._Find_first();j<32;j=b._Find_next(j)){
                        chmin(dp[state][i],dis[i][j]+dp[b.to_ulong()][j]);
                    }
                }
                b.set(i);
            }
        }
        auto it=min_element(dp[(1<<n)-1],dp[1<<n]);
        dfs((1<<n)-1,it-dp[(1<<n)-1],*it,words);
        return ans;
    }
};


int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<string>words{
        "catg","ctaagt","gcta","ttca","atgcatc"
    };
    auto ans=sol.shortestSuperstring(words);
    DBG(ans);

    system("pause");
    return 0;
}
