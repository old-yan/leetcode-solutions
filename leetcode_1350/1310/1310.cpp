#include "utils.h"

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        partial_sum(ALL(arr),arr.begin(),[](int x,int y){return x^y;});
        vi ans;
        for(auto&q:queries){
            if(q[0]==0)ans.pb(arr[q[1]]);
            else ans.pb(arr[q[1]]^arr[q[0]-1]);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi arr{1,3,4,8};
    vvi queries=makevvi("[[0,1],[1,2],[0,3],[3,3]]");
    auto ans=sol.xorQueries(arr,queries);
    DBGV(ans);

    system("pause");
    return 0;
}
