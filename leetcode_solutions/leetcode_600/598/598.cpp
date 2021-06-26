#include "utils.h"

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int mini=m-1,minj=n-1;
        for(auto&A:ops){
            int i=A[0],j=A[1];
            chmin(mini,i);
            chmin(minj,j);
        }
        return (mini+1)*(minj+1);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int m=3;
    int n=3;
    vvi ops{
        {2,2},{3,3}
    };
    auto ans=sol.maxCount(m,n,ops);
    DBG(ans);

    system("pause");
    return 0;
}
