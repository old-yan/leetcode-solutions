#include "utils.h"

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int update[1001]={0};
        for(auto&trip:trips){
            update[trip[1]]+=trip[0];
            update[trip[2]]-=trip[0];
        }
        int cur=capacity;
        REP(i,1001){
            cur-=update[i];
            if(cur<0)return false;
        }
        return true;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi trips=makevvi("[[2,1,5],[3,3,7]]");
    int capacity=4;
    auto ans=sol.carPooling(trips,capacity);
    DBG(ans);

    system("pause");
    return 0;
}
