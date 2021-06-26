#include "utils.h"

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        unordered_map<int,vi>M;
        M[0].pb(-1);
        partial_sum(ALL(arr),arr.begin());
        REP(i,arr.size())M[arr[i]].pb(i);
        int ans=0;
        for(auto&it:M){
            auto&v=it.second;
            REP(i,v.size()){
                REP(j,i){
                    ans+=v[i]-v[j]-1;
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

    vi arr{2,3,1,6,7};
    auto ans=sol.countTriplets(arr);
    DBG(ans);

    system("pause");
    return 0;
}
