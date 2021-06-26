#include "utils.h"

class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        int A[52];
        for(auto&r:ranges){
            A[r[0]]++;
            A[r[1]+1]--;
        }
        partial_sum(A,A+52,A);
        return !count(A+left,A+right+1,0);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi ranges=makevvi("[[1,2],[3,4],[5,6]]");
    int left=2;
    int right=5;
    auto ans=sol.isCovered(ranges,left,right);
    DBG(ans);

    system("pause");
    return 0;
}
