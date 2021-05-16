#include "Union.h"
#include "utils.h"

class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        int m=queries.size();
        vi idxes(m);
        iota(ALL(idxes),0);
        sort(ALL(idxes),[&](int x,int y){return queries[x][2]<queries[y][2];});
        vector<bool>ans(m);
        sort(ALL(edgeList),[](vi&x,vi&y){return x[2]<y[2];});
        int cursor=0;
        Union u(n);
        for(auto idx:idxes){
            auto&q=queries[idx];
            while(cursor<edgeList.size()&&edgeList[cursor][2]<q[2]){
                u.unite(edgeList[cursor][0],edgeList[cursor][1]);
                cursor++;
            }
            ans[idx]=u.same(q[0],q[1]);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=3;
    vvi edgeList=makevvi("[[0,1,2],[1,2,4],[2,0,8],[1,0,16]]");
    vvi queries=makevvi("[[0,1,2],[0,2,5]]");
    auto ans=sol.distanceLimitedPathsExist(n,edgeList,queries);
    DBGV(ans);

    system("pause");
    return 0;
}
