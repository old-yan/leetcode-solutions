#include "utils.h"

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        int dist[n];
        memset(dist,0x3f,sizeof(dist));
        unordered_map<int,vi>M;
        REP(i,n)M[arr[i]].pb(i);
        queue<pair<int,int>>Q;
        dist[0]=0;
        Q.emplace(0,0);
        while(Q.size()){
            auto [cur,dis]=Q.front();
            Q.pop();
            auto find=M.find(arr[cur]);
            if(find!=M.end()){
                for(int a:find->second){
                    if(chmin(dist[a],dis+1)){
                        Q.emplace(a,dis+1);
                    }
                }
                M.erase(find);
            }
            if(cur+1<n&&chmin(dist[cur+1],dis+1)){
                Q.emplace(cur+1,dis+1);
            }
            if(cur-1>=0&&chmin(dist[cur-1],dis+1)){
                Q.emplace(cur-1,dis+1);
            }
        }
        return dist[n-1];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi arr{100,-23,-23,404,100,23,23,23,3,404};
    auto ans=sol.minJumps(arr);
    DBG(ans);

    system("pause");
    return 0;
}
