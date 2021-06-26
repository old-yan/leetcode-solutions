#include "utils.h"

class Solution {
public:
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        auto closer=[](int a,int b,int target){
            return tuple{abs(a-target),a}<tuple{abs(b-target),b};
        };
        vi idxes(queries.size());
        iota(ALL(idxes),0);
        sort(ALL(idxes),[&](int x,int y){return queries[x][1]>queries[y][1];});
        priority_queue<pair<int,int>>Q;
        for(auto&r:rooms){
            Q.emplace(r[1],r[0]);
        }
        set<int>S;
        vi ans(queries.size(),-1);
        for(auto idx:idxes){
            auto &q=queries[idx];
            while(Q.size()&&Q.top().first>=q[1]){
                S.insert(Q.top().second);
                Q.pop();
            }
            auto it=S.lower_bound(q[0]);
            if(it!=S.end()){
                if(ans[idx]<0||closer(*it,ans[idx],q[0]))ans[idx]=*it;
            }
            if(it!=S.begin()){
                --it;
                if(ans[idx]<0||closer(*it,ans[idx],q[0]))ans[idx]=*it;
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi rooms=makevvi("[[2,2],[1,2],[3,2]]");
    vvi queries=makevvi("[[3,1],[3,3],[5,2]]");
    auto ans=sol.closestRoom(rooms,queries);
    DBGV(ans);

    system("pause");
    return 0;
}
