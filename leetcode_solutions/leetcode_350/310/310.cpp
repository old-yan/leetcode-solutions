#include "utils.h"

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1)return {0};
        vi v[n];
        int visited[n];
        memset(visited,0,sizeof(visited));
        for(auto&A:edges){
            int i=A[0],j=A[1];
            v[i].pb(j);
            v[j].pb(i);
        }
        queue<int>Q;
        REP(i,n){
            if(visited[i]==v[i].size()-1){
                visited[i]++;
                Q.push(i);
            }
        }
        vi ans;
        while(int l=Q.size()){
            ans.clear();
            while(l--){
                auto a=Q.front();
                ans.pb(a);
                Q.pop();
                for(int b:v[a]){
                    if(++visited[b]==v[b].size()-1){
                        Q.push(b);
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

    int n=6;
    vvi edges{
        {3,0},{3,1},{3,2},{3,4},{5,4}
    };
    auto ans=sol.findMinHeightTrees(n,edges);
    DBGV(ans);

    system("pause");
    return 0;
}
