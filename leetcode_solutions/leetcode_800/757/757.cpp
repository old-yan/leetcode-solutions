#include "utils.h"

class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(ALL(intervals));
        int p=INT_MAX,q=INT_MAX;
        int ans=0;
        REPR(i,intervals.size()-1){
            int start=intervals[i][0],end=intervals[i][1];
            if(p>end){
                p=start;
                q=start+1;
                ans+=2;
            }
            else if(q>end){
                if(p==start)q=start+1;
                else{
                    q=p;
                    p=start;
                }
                ans++;
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi intervals=makevvi("[[1, 3], [1, 4], [2, 5], [3, 5]]");
    auto ans=sol.intersectionSizeTwo(intervals);
    DBG(ans);

    system("pause");
    return 0;
}
