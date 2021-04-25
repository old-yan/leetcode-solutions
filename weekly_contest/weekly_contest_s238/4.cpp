#include "utils.h"

int first[200005],nxt[200005],to[200005],dis[200005],cnt;
int h[200005];
void addedge(int _from,int _to,int _dis){
    nxt[cnt]=first[_from];
    first[_from]=cnt;
    to[cnt]=_to;
    dis[cnt++]=_dis;
}

class Solution {
    void init(){
        cnt=0;
        memset(first,0xff,sizeof(first));
    }
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        init();
        restrictions.push_back({1,0});
        sort(ALL(restrictions));
        if(restrictions.back()[0]!=n)restrictions.push_back({n,n-1});
        int m=restrictions.size();
        FOR(i,1,m){
            addedge(i,i-1,restrictions[i][0]-restrictions[i-1][0]);
            addedge(i-1,i,restrictions[i][0]-restrictions[i-1][0]);
        }
        static stack<int>S;
        vector<bool>instack(m,false);
        REP(i,m){
            instack[i]=true;
            S.push(i);
        }
        while(S.size()){
            auto cur=S.top();
            int curdis=restrictions[cur][1];
            S.pop();
            instack[cur]=false;
            for(int i=first[cur];~i;i=nxt[i]){
                if(chmin(restrictions[to[i]][1],curdis+dis[i])&&!instack[to[i]]){
                    instack[to[i]]=true;
                    S.push(to[i]);
                }
            }
        }
        int curid=0,curh=0,ans=0;
        for(auto&r:restrictions){
            int id=r[0],h=r[1];
            if(h>=curh+id-curid){
                curh+=id-curid;
                chmax(ans,curh);
            }
            else{
                chmax(ans,(id-curid+curh+h)/2);
                curh=h;
            }
            curid=id;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=10;
    vvi restrictions=makevvi("[[5,3],[2,5],[7,4],[10,3]]");
    auto ans=sol.maxBuilding(n,restrictions);
    DBG(ans);

    system("pause");
    return 0;
}
