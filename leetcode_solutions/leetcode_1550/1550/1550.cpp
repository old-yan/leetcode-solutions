#include "utils.h"

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        FOR(i,2,arr.size()){
            if(arr[i]%2&&arr[i-1]%2&&arr[i-2]%2)return true;
        }
        return false;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi arr{1,2,34,3,4,5,7,23,12};
    auto ans=sol.threeConsecutiveOdds(arr);
    DBG(ans);

    system("pause");
    return 0;
}
