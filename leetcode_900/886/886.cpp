#include "utils.h"

class Solution {
    vi adj[2000];
    int Type[2000];
    bool dislike=false;
    void traverse(int idx,int type){
        Type[idx]=type;
        for(int a:adj[idx]){
            if(Type[a]){
                if(Type[a]==Type[idx])dislike=true;
            }
            else traverse(a,1-type);
        }
    }
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        for(auto&e:dislikes){
            int i=e[0]-1,j=e[1]-1;
            adj[i].pb(j);
            adj[j].pb(i);
        }
        memset(Type,0xff,sizeof(Type));
        REP(i,N){
            if(Type[i]<0){
                traverse(i,0);
            }
        }
        return !dislike;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int N=4;
    vvi dislikes=makevvi("[[1,2],[1,3],[2,4]]");
    auto ans=sol.possibleBipartition(N,dislikes);
    DBG(ans);

    system("pause");
    return 0;
}
