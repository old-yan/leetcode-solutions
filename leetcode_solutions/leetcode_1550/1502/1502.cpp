#include "utils.h"

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(ALL(arr));
        adjacent_difference(ALL(arr),arr.begin());
        FOR(i,2,arr.size()){
            if(arr[i]!=arr[1])return false;
        }
        return true;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi arr{3,5,1};
    auto ans=sol.canMakeArithmeticProgression(arr);
    DBG(ans);

    system("pause");
    return 0;
}
