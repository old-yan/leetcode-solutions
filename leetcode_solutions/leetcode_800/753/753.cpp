#include "utils.h"

class Solution {
    bitset<10>adj[10000];
    int mod,k;
    string ans;
    bool visited[10000]={0};
    void dfs(int cur){
        if(visited[cur])return;
        visited[cur]=true;
        while(adj[cur].count()){
            int next=adj[cur]._Find_first();
            adj[cur].reset(next);
            dfs(cur%mod*k+next);
        }
        ans+='0'+cur%k;
    }
public:
    string crackSafe(int n, int _k) {
        k=_k;
        mod=pow(k,n-1);
        REP(i,pow(k,n)){
            int rest=i%mod;
            REP(j,k){
                if(rest*k+j!=i)adj[i].set(j);
            }
        }
        dfs(0);
        ans+=string(n-1,'0');
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=2;
    int k=2;
    auto ans=sol.crackSafe(n,k);
    DBG(ans);

    system("pause");
    return 0;
}
