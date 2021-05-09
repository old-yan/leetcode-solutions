#include "utils.h"

class Solution {
    vi pos[26];
    int left[26],right[26],n;
    bool contain(int x,int y){
        auto it=lower_bound(ALL(pos[y]),pos[x].front());
        return it!=pos[y].end()&&*it<=pos[x].back();
    }
    void findBorder(int cur){
        bitset<26>visited;
        static queue<int>Q;
        visited.set(cur);
        Q.push(cur);
        while(Q.size()){
            auto p=Q.front();
            Q.pop();
            chmin(left[cur],pos[p].front());
            chmax(right[cur],pos[p].back());
            REP(i,26)if(!visited[i]&&contain(p,i)){
                visited.set(i);
                Q.push(i);
            }
        }
    }
public:
    vector<string> maxNumOfSubstrings(string s) {
        n=s.size();
        REP(i,n)pos[s[i]-'a'].pb(i);
        memset(left,0x3f,sizeof(left));
        memset(right,0xff,sizeof(right));
        REP(i,26)if(pos[i].size())findBorder(i);
        int dp[27];
        memset(dp,0x3f,sizeof(dp));
        dp[0]=-1;
        REP(i,n){
            FORR(j,26,1){
                if(dp[j-1]<left[s[i]-'a']){
                    chmin(dp[j],right[s[i]-'a']);
                }
            }
        }
        vector<string>ans;
        FORR(i,26,1){
            if(dp[i]<0x3f3f3f3f){
                ans.pb(s.substr(left[s[dp[i]]-'a'],dp[i]-left[s[dp[i]]-'a']+1));
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="adefaddaccc";
    auto ans=sol.maxNumOfSubstrings(s);
    DBGV(ans);

    system("pause");
    return 0;
}
