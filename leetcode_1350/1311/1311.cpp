#include "utils.h"

class Solution {
    int dp[100];
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        memset(dp,0x3f,sizeof(dp));
        queue<pair<int,int>>Q;
        dp[id]=0;
        Q.emplace(id,0);
        while(Q.size()){
            auto [p,dis]=Q.front();
            Q.pop();
            for(int a:friends[p]){
                if(chmin(dp[a],dis+1))Q.emplace(a,dis+1);
            }
        }
        unordered_map<string,int>M;
        REP(i,watchedVideos.size()){
            if(dp[i]==level){
                for(string&s:watchedVideos[i])M[s]++;
            }
        }
        vector<string>ans;
        for(auto&it:M)ans.pb(it.first);
        sort(ALL(ans),[&](string&x,string&y){
            if(M[x]!=M[y])return M[x]<M[y];
            else return x<y;
        });
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<vector<string>>watchWideos{
        {"A","B"},{"C"},{"B","C"},{"D"}
    };
    vvi friends=makevvi("[[1,2],[0,3],[0,3],[1,2]]");
    int id=0;
    int level=1;
    auto ans=sol.watchedVideosByFriends(watchWideos,friends,id,level);
    DBGV(ans);

    system("pause");
    return 0;
}
