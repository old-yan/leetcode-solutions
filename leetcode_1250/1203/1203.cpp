#include "utils.h"

class Solution {
    int n,m;
    vi Deg;
    vi Adj[30000];
    vi deg;
    vi adj[30000];
    vi member[30000];
    vi ans;
    void setGroup(vi&group){
        static bitset<30000>tobeused;
        tobeused.set();
        for(int g:group)if(g>=0)tobeused.reset(g);
        REP(i,n){
            if(group[i]<0){
                int g=tobeused._Find_first();
                tobeused.reset(g);
                group[i]=g;
                chmax(m,g+1);
            }
        }
    }
    void getAdj(vi&group,vvi&beforeItems){
        Deg.resize(m,0);
        deg.resize(n,0);
        REP(a,n){
            int g=group[a];
            member[g].pb(a);
            for(int b:beforeItems[a]){
                int g2=group[b];
                if(g!=g2){
                    Adj[g2].pb(g);
                    Deg[g]++;
                }
                else{
                    adj[b].pb(a);
                    deg[a]++;
                }
            }
        }
    }
    bool Topo(){
        static queue<int>Q;
        int total=0;
        REP(i,m){
            if(!Deg[i]&&member[i].size())Q.push(i);
        }
        while(Q.size()){
            auto g=Q.front();
            Q.pop();
            {
                static queue<int>Q2;
                for(int a:member[g]){
                    if(!deg[a])Q2.push(a);
                }
                while(Q2.size()){
                    int a=Q2.front();
                    Q2.pop();
                    ans.pb(a);
                    for(int b:adj[a]){
                        if(!--deg[b]){
                            Q2.push(b);
                        }
                    }
                }
                if(ans.size()<total+member[g].size())return false;
                total=ans.size();
            }
            for(int g2:Adj[g]){
                if(!--Deg[g2]){
                    Q.push(g2);
                }
            }
        }
        return total==n;
    }
public:
    vector<int> sortItems(int _n, int _m, vector<int>& group, vector<vector<int>>& beforeItems) {
        n=_n,m=_m;
        setGroup(group);
        getAdj(group,beforeItems);
        if(Topo())return ans;
        else return {};
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=8;
    int m=2;
    vi group{-1,-1,1,0,0,1,0,-1};
    vvi beforeItems=makevvi("[[],[6],[5],[6],[3,6],[],[],[]]");
    auto ans=sol.sortItems(n,m,group,beforeItems);
    DBGV(ans);

    system("pause");
    return 0;
}
