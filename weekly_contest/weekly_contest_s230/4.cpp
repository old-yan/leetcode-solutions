#include "utils.h"

class Solution {
public:
    //这道题必须想清楚一点，那就是如果ans[i]有正值，那么一定是cars[i]和某个cars[j]（j>i且speed[j]<speed[i]）
    //相撞之后，所谓的融合，其实可以理解为cars[i]消失了，cars[j]状态不变
    //所以我们只关注一辆车后面，不关注其前面，它的前面对它没有任何影响。可以考虑从后往前遍历
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        vector<double>ans(cars.size());
        //设立一个类似单调栈的栈，栈底最慢，栈顶最快
        stack<int>S;
        for(int i=cars.size()-1;i>=0;i--){
            while(S.size()){
                //如果栈顶比我快，我追不上它，可以考虑等它消失之后我去撞它前面的，所以将它pop
                if(cars[S.top()][1]>=cars[i][1])S.pop();
                //如果栈顶比我慢，我就决定去碰它了
                else{
                    //如果它不会消失，那我肯定能碰它，break
                    if(ans[S.top()]<0)break;
                    //如果它会消失，我需要计算一下在它消失之前能否追上它
                    double d=ans[S.top()]*(cars[i][1]-cars[S.top()][1]);
                    //能追上，那我肯定碰它，break
                    if(d>cars[S.top()][0]-cars[i][0])break;
                    //追不上，那算了，追它前面的车
                    else S.pop();
                }
            }
            if(S.empty())ans[i]=-1;
            else{
                //相对距离除以相对速度
                double t=double(cars[S.top()][0]-cars[i][0])/double(cars[i][1]-cars[S.top()][1]);
                ans[i]=t;
            }
            S.push(i);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi cars=makevvi("[3,4],[5,4],[6,3],[9,1]");
    auto ans=sol.getCollisionTimes(cars);
    DBGV(ans);

    system("pause");
    return 0;
}
