#include "utils.h"

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int,int>M;
        int maxGap=0;
        for(auto&w:wall){
            partial_sum(ALL(w),w.begin());
            for(int a:w){
                if(a<w.back())chmax(maxGap,++M[a]);
            }
        }
        return wall.size()-maxGap;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi wall{
        {1,2,2,1},
        {3,1,2},
        {1,3,2},
        {2,4},
        {3,1,2},
        {1,3,1,1}
    };
    auto ans=sol.leastBricks(wall);
    DBG(ans);

    system("pause");
    return 0;
}
