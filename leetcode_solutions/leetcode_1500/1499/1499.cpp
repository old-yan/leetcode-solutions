#include "utils.h"

class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        deque<pair<int,int>>Q;
        int ans=INT_MIN;
        for(int left=0,right=0;right<points.size();right++){
            while(Q.size()&&Q.front().second<points[right][0]-k)Q.pop_front();
            if(Q.size()){
                chmax(ans,points[right][0]+points[right][1]+Q.front().first);
                while(Q.back().first<=points[right][1]-points[right][0])Q.pop_back();
            }
            Q.emplace_back(points[right][1]-points[right][0],points[right][0]);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi points=makevvi("[[1,3],[2,0],[5,10],[6,-10]]");
    int k=1;
    auto ans=sol.findMaxValueOfEquation(points,k);
    DBG(ans);

    system("pause");
    return 0;
}
