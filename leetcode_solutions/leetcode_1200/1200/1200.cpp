#include "utils.h"

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        auto copy=arr;
        sort(ALL(copy));
        auto dif=copy;
        adjacent_difference(ALL(copy),dif.begin());
        int Min=*min_element(dif.begin()+1,dif.end());
        vvi ans;
        FOR(i,1,dif.size()){
            if(dif[i]==Min){
                ans.pb(copy[i-1],copy[i]);
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi arr{3,8,-10,23,19,-4,-14,27};
    auto ans=sol.minimumAbsDifference(arr);
    DBGVV(ans);

    system("pause");
    return 0;
}
