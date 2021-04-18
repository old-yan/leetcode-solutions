#include "utils.h"

class Solution {
    bool check(vector<int>&A,vector<int>&B){
        if(A[0]>B.back()||A.back()<B[0])return false;
        for(int i=0,j=0;i<A.size()&&j<B.size();){
            if(A[i]<B[j])i++;
            else if(A[i]>B[j])j++;
            else return true;
        }
        return false;
    }
    vi adj[500];
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source==target)return 0;
        for(auto&route:routes)sort(ALL(route));
        queue<int>Q;
        bitset<500>visited;
        bitset<500>can;
        REP(i,routes.size()){
            if(binary_search(ALL(routes[i]),source)){
                Q.push(i);
                visited.set(i);
            }
            if(binary_search(ALL(routes[i]),target)){
                if(visited[i])return 1;
                can.set(i);
            }
            REP(j,i){
                if(check(routes[i],routes[j])){
                    adj[i].pb(j);
                    adj[j].pb(i);
                }
            }
        }
        int len=2;
        while(int l=Q.size()){
            while(l--){
                auto p=Q.front();
                Q.pop();
                for(int a:adj[p]){
                    if(!visited[a]){
                        if(can[a])return len;
                        visited.set(a);
                        Q.push(a);
                    }
                }
            }
            len++;
        }
        return -1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi routes=makevvi("[[1,2,7],[3,6,7]]");
    int source=1;
    int target=6;
    auto ans=sol.numBusesToDestination(routes,source,target);
    DBG(ans);

    system("pause");
    return 0;
}
