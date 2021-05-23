#include "utils.h"

class Solution {
    struct node{
        int p[51];
        node(){
            memset(p,0xff,sizeof(p));
        }
    };
    int n,val[100000],_depth[100001];
    int *depth;
    bool prime[51][51]={0};
    vi adj[100000],ans;
    void init(){
        depth=_depth+1;
        depth[-1]=-1;
        FOR(i,1,51)FOR(j,1,51){
            if(gcd(i,j)==1)prime[i][j]=true;
        }
    }
    void dfs(int cur,int p,node nn,int d){
        FOR(i,1,51){
            if(nn.p[i]>=0&&prime[i][val[cur]]){
                if(depth[nn.p[i]]>depth[ans[cur]])ans[cur]=nn.p[i];
            }
        }
        depth[cur]=d;
        nn.p[val[cur]]=cur;
        for(int a:adj[cur])if(a!=p){
            dfs(a,cur,nn,d+1);
        }
    }
public:
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        init();
        n=nums.size();
        REP(i,n)val[i]=nums[i];
        for(auto&e:edges){
            int i=e[0],j=e[1];
            adj[i].pb(j);
            adj[j].pb(i);
        }
        ans.resize(n,-1);
        dfs(0,-1,node(),0);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{2,3,3,2};
    vvi edges=makevvi("[[0,1],[1,2],[1,3]]");
    auto ans=sol.getCoprimes(nums,edges);
    DBGV(ans);

    system("pause");
    return 0;
}
