#include "utils.h"

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        vi rowmax(m,-1);
        auto getrowmax=[&](int r){
            if(rowmax[r]<0)
                rowmax[r]=max_element(ALL(mat[r]))-mat[r].begin();
        };
        int low=0,high=m-1;
        while(low<high){
            int mid=(low+high)/2;
            getrowmax(mid);
            bool up=!mid||mat[mid][rowmax[mid]]>mat[mid-1][rowmax[mid]];
            bool down=mid==m-1||mat[mid][rowmax[mid]]>mat[mid+1][rowmax[mid]];
            if(up&&down)return {mid,rowmax[mid]};
            if(!down)low=mid+1;
            else high=mid;
        }
        getrowmax(low);
        return {low,rowmax[low]};
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi mat=makevvi("[[1,4],[3,2]]");
    auto ans=sol.findPeakGrid(mat);
    DBGV(ans);

    system("pause");
    return 0;
}
