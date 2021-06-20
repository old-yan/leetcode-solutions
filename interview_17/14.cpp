#include "utils.h"

class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        nth_element(arr.begin(),arr.begin()+k,arr.end());
        arr.resize(k);
        return arr;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi arr{1,3,5,7,2,4,6,8};
    int k=4;
    auto ans=sol.smallestK(arr,k);
    DBGV(ans);

    system("pause");
    return 0;
}
