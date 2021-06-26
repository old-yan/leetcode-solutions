#include "utils.h"

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vi idx_right(n);
        iota(ALL(idx_right),0);
        sort(ALL(idx_right),[&](int x,int y)->bool{return intervals[x][1]<intervals[y][1];});
        vi idx_left(n);
        iota(ALL(idx_left),0);
        sort(ALL(idx_left),[&](int x,int y)->bool{return intervals[x][0]<intervals[y][0]||(intervals[x][0]==intervals[y][0]&&x<y);});
        vi ans(n);
        for(int i=0,j=0;i<n;i++){
            while(j<n&&intervals[idx_left[j]][0]<intervals[idx_right[i]][1])j++;
            if(j==n)ans[idx_right[i]]=-1;
            else ans[idx_right[i]]=idx_left[j];
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi intervals{
        {3,4}, {2,5},{2,3},{2,4},{1,2}
    };
    auto ans=sol.findRightInterval(intervals);
    DBGV(ans);

    system("pause");
    return 0;
}
