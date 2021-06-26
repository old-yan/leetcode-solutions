#include "utils.h"

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int m=rowSum.size(),n=colSum.size();
        vvi ans(m,vi(n,0));
        priority_queue<pair<int,int>>Q1,Q2;
        REP(i,m)if(rowSum[i])Q1.emplace(rowSum[i],i);
        REP(j,n)if(colSum[j])Q2.emplace(colSum[j],j);
        while(Q1.size()){
            auto [rs,r]=Q1.top();
            Q1.pop();
            auto [cs,c]=Q2.top();
            Q2.pop();
            int val=min(rs,cs);
            ans[r][c]+=val;
            if(rs>val)Q1.emplace(rs-val,r);
            if(cs>val)Q2.emplace(cs-val,c);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi rowSum{3,8};
    vi colSum{4,7};
    auto ans=sol.restoreMatrix(rowSum,colSum);
    DBGVV(ans);

    system("pause");
    return 0;
}
