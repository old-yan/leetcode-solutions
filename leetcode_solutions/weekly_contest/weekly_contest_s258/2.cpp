#include "utils.h"

class Solution {
public:
    //对于分数，尽量不要以浮点数形式存储，否则可能产生意料之外的误差
    //分数=有理数=互质数对，这样就可以精确地确定一个分数
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        //使用map对分数进行计数
        map<pair<int,int>,int>M;
        for(auto&rect:rectangles){
            int a=rect[0],b=rect[1];
            int g=mygcd(a,b);
            M[{a/g,b/g}]++;
        }
        //注意使用long long
        ll ans=0;
        for(auto [fraction,cnt]:M){
            ans+=(ll)cnt*(cnt-1)/2;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi rectangles=makevvi("[[4,8],[3,6],[10,20],[15,30]]");
    auto ans=sol.interchangeableRectangles(rectangles);
    DBG(ans);

    system("pause");
    return 0;
}
