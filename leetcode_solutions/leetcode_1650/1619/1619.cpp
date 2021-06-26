#include "utils.h"

class Solution {
public:
    double trimMean(vector<int>& arr) {
        int n=arr.size();
        sort(ALL(arr));
        int sum=accumulate(arr.begin()+n/20,arr.end()-n/20,0);
        return sum/(n*0.9);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi arr{1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3};
    auto ans=sol.trimMean(arr);
    DBG(ans);

    system("pause");
    return 0;
}
