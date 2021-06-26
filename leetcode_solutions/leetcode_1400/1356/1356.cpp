#include "utils.h"

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(ALL(arr),[](int x,int y){
            if(__builtin_popcount(x)!=__builtin_popcount(y))return __builtin_popcount(x)<__builtin_popcount(y);
            else return x<y;
        });
        return arr;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi arr{0,1,2,3,4,5,6,7,8};
    auto ans=sol.sortByBits(arr);
    DBGV(ans);

    system("pause");
    return 0;
}
