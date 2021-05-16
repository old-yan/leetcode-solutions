#include "utils.h"

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int pre=heights[0];
        priority_queue<int,vi,greater<int>>Q;
        FOR(i,1,heights.size()){
            int cur=heights[i];
            if(cur>pre){
                if(ladders){
                    Q.push(cur-pre);
                    ladders--;
                }
                else{
                    Q.push(cur-pre);
                    auto p=Q.top();
                    Q.pop();
                    if(bricks>=p){
                        bricks-=p;
                    }
                    else{
                        return i-1;
                    }
                }
            }
            pre=cur;
        }
        return heights.size()-1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi heights{4,2,7,6,9,14,12};
    int bricks=5;
    int ladders=1;
    auto ans=sol.furthestBuilding(heights,bricks,ladders);
    DBG(ans);

    system("pause");
    return 0;
}
