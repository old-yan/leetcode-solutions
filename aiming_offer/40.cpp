#include "utils.h"

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        nth_element(arr.begin(),arr.begin()+k,arr.end());
        arr.resize(k);
        return arr;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi arr{3,2,1};
    int k=2;
    auto ans=sol.getLeastNumbers(arr,k);
    DBGV(ans);

    system("pause");
    return 0;
}
