#include "utils.h"

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vvi ans;
        if(!numRows)return ans;
        ans.pb(vi{1});
        FOR(i,1,numRows){
            vi&pre=ans.back();
            vi cur(pre.size()+1,0);
            REP(j,pre.size()){
                cur[j]+=pre[j];
                cur[j+1]+=pre[j];
            }
            ans.pb(cur);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int numRows=5;
    auto ans=sol.generate(numRows);
    DBGVV(ans);

    system("pause");
    return 0;
}
