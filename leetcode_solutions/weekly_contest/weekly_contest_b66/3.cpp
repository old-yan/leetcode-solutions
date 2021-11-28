#include "utils.h"

class Solution {
public:
    //显然，只要不走回头路，那么随便怎么走的代价都是最小代价
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        //不妨先跨行
        if(startPos[0]<homePos[0]){
            for(int row=startPos[0];++row<=homePos[0];){
                ans+=rowCosts[row];
            }
        }
        else{
            for(int row=startPos[0];--row>=homePos[0];){
                ans+=rowCosts[row];
            }
        }
        //再跨列
        if(startPos[1]<homePos[1]){
            for(int col=startPos[1];++col<=homePos[1];){
                ans+=colCosts[col];
            }
        }
        else{
            for(int col=startPos[1];--col>=homePos[1];){
                ans+=colCosts[col];
            }
        }
        return ans;
    }
    int ans=0;
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<int>startPos{1, 0};
    vector<int>homePos{2, 3};
    vector<int>rowCosts{5, 4, 3};
    vector<int>colCosts{8, 2, 6, 7};
    auto ans=sol.minCost(startPos,homePos,rowCosts,colCosts);
    DBG(ans);

    system("pause");
    return 0;
}