#include "utils.h"

class Solution {
    vi v[501];
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vvi ans;
        REP(i,groupSizes.size()){
            v[groupSizes[i]].pb(i);
        }
        FOR(i,1,501){
            int cur=0;
            for(int a:v[i]){
                if(cur==0)ans.pb(vi());
                ans.back().pb(a);
                cur=(cur+1)%i;
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi groupSizes{3,3,3,3,3,1,3};
    auto ans=sol.groupThePeople(groupSizes);
    DBGVV(ans);

    system("pause");
    return 0;
}
