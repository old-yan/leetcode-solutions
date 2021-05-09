#include "utils.h"

class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int a[m];
        memset(a,0,sizeof(a));
        REP(i,m){
            REPR(j,n-1){
                if(!grid[i][j])a[i]++;
                else break;
            }
        }
        int ans=0;
        REP(i,m){
            int idx;
            for(idx=i;idx<m&&a[idx]<n-1-i;idx++);
            if(idx==m)return -1;
            ans+=idx-i;
            while(idx>i){
                a[idx]=a[idx-1];
                idx--;
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi grid=makevvi("[[0,0,1],[1,1,0],[1,0,0]]");
    auto ans=sol.minSwaps(grid);
    DBG(ans);

    system("pause");
    return 0;
}
