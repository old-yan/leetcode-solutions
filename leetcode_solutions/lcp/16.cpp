#include "utils.h"

class Solution {
    struct node{
        int i,j,w;
        node(int _i,int _j,int _w):i(_i),j(_j),w(_w){}
        bool operator<(const node&other)const{
            return w<other.w;
        }
        int operator+(const node&other)const{
            if(i==other.i||i==other.j)return i;
            else if(j==other.i||j==other.j)return j;
            else return -1;
        }
    };
    int n;
    int deg[10000]={0};
    vi adj[10000];
    unordered_set<int>S;
public:
    int maxWeight(vector<vector<int>>& edges, vector<int>& value) {
        n=value.size();
        for(auto&e:edges){
            deg[e[0]]++;
            deg[e[1]]++;
        }
        for(auto&e:edges){
            int&i=e[0],&j=e[1];
            if(deg[i]>deg[j]||(deg[i]==deg[j]&&i>j))swap(i,j);
            S.insert(i*n+j);
            adj[i].pb(j);
        }
        int ans=0;
        vector<node>vv[n];
        for(auto&e:edges){
            int i=e[0],j=e[1];
            for(int a:adj[j])if(S.count(i*n+a)){
                vv[i].emplace_back(j,a,value[j]+value[a]);
                vv[j].emplace_back(i,a,value[i]+value[a]);
                vv[a].emplace_back(i,j,value[i]+value[j]);
            }
        }
        auto update=[&](vector<node>&v,int k){
            if(v.empty())return;
            if(v.size()==1)chmax(ans,value[k]+v[0].w);
            else{
                sort(ALLR(v));
                if(v[0]+v[1]<0){
                    chmax(ans,value[k]+v[0].w+v[1].w);
                }
                else{
                    REP(i,3)if(i<v.size()){
                        FOR(j,i+1,v.size()){
                            int same=v[i]+v[j];
                            if(same>=0)chmax(ans,value[k]+v[i].w+v[j].w-value[same]);
                            else{
                                chmax(ans,value[k]+v[i].w+v[j].w);
                                break;
                            }
                        }
                    }
                }
            }
        };
        REP(k,n){
            update(vv[k],k);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi edges=makevvi("[[0,1],[1,2],[0,2]]");
    vi values{1,2,3};
    auto ans=sol.maxWeight(edges,values);
    DBG(ans);

    system("pause");
    return 0;
}
