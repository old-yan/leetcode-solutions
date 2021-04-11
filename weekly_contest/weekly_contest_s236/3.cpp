#include "utils.h"

class Solution {
    #define INF 0x3f3f3f3f
public:
    //从右往左倒推
    int minSideJumps(vector<int>& obstacles) {
        int n=obstacles.size()-1;
        int step[3]={0};
        for(int i=n;i>=0;i--){
            for(int j=0;j<3;j++){
                //从右列到左列的转移，不会增加横跳次数
                step[j]=j+1==obstacles[i]?INF:step[j];
            }
            int Min=*min_element(step,step+3);
            for(int j=0;j<3;j++){
                //列内的转移，增加一次横跳次数
                step[j]=j+1==obstacles[i]?INF:min(step[j],Min+1);
            }
        }
        return step[1];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi obstacles{0,1,2,3,0};
    auto ans=sol.minSideJumps(obstacles);
    DBG(ans);

    system("pause");
    return 0;
}
