#include "utils.h"

class Solution {
    unordered_map<int,vi>M;
    bitset<1000000>person_visited;
    bitset<100000>route_visited;
    bitset<100000>can;
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source==target)return 0;
        REP(i,routes.size()){
            for(int a:routes[i]){
                if(a==target)can.set(i);
                M[a].pb(i);
            }
        }
        queue<int>Q;
        int step=1;
        person_visited.set(source);
        for(int route:M[source]){
            if(can[route])return 1;
            route_visited.set(route);
            Q.push(route);
        }
        step++;
        while(int l=Q.size()){
            while(l--){
                auto p=Q.front();
                Q.pop();
                for(int a:routes[p]){
                    if(!person_visited[a]){
                        person_visited.set(a);
                        for(int route:M[a]){
                            if(!route_visited[route]){
                                if(can[route])return step;
                                route_visited.set(route);
                                Q.push(route);
                            }
                        }
                    }
                }
            }
            step++;
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
