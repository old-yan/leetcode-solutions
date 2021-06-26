#include "utils.h"

class Solution {
public:
    vector<int> gridIllumination(int N, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        unordered_map<int,int>col,row,ltrb,rtlb;
        set<pair<int,int>>S;
        for(auto&lamp:lamps){
            if(!S.emplace(lamp[0],lamp[1]).second)continue;
            row[lamp[0]]++;
            col[lamp[1]]++;
            ltrb[lamp[0]-lamp[1]]++;
            rtlb[lamp[0]+lamp[1]]++;
        }
        vi ans;
        for(auto&q:queries){
            if(row.count(q[0])||col.count(q[1])||ltrb.count(q[0]-q[1])||rtlb.count(q[0]+q[1]))ans.pb(1);
            else ans.pb(0);
            FOR(i,q[0]-1,q[0]+2){
                FOR(j,q[1]-1,q[1]+2){
                    if(S.count({i,j})){
                        S.erase({i,j});
                        if(!--row[i])row.erase(i);
                        if(!--col[j])col.erase(j);
                        if(!--ltrb[i-j])ltrb.erase(i-j);
                        if(!--rtlb[i+j])rtlb.erase(i+j);
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

    int N=5;
    vvi lamps=makevvi("[[0,0],[0,4]]");
    vvi queries=makevvi("[[0,4],[0,1],[1,4]]");
    auto ans=sol.gridIllumination(N,lamps,queries);
    DBGV(ans);

    system("pause");
    return 0;
}
