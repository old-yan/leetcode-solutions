#include "utils.h"

class Solution {
public:
    vector<int> subSort(vector<int>& array) {
        auto preMax=premax(array);
        auto postMin=postmin(array);
        int l=0,r=array.size()-1;
        while(l<array.size()&&array[l]<=postMin[l])l++;
        while(r>=0&&array[r]>=preMax[r])r--;
        if(l>r)return {-1,-1};
        else return {l,r};
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi array{1,2,4,7,10,11,7,12,6,7,16,18,19};
    auto ans=sol.subSort(array);
    DBGV(ans);

    system("pause");
    return 0;
}
