#include "utils.h"

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int i=0,j=n,ans=0;
        while(i<m){
            while(j-1>=0&&grid[i][j-1]<0)j--;
            ans+=n-j;
            i++;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi grid=makevvi("[[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]");
    auto ans=sol.countNegatives(grid);
    DBG(ans);

    system("pause");
    return 0;
}
