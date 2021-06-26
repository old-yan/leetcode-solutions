#include "utils.h"

class Solution {
public:
    //贪心问题，看数据范围可以暴力解决，也可以耍小聪明
    int maximumScore(int a, int b, int c) {
        vi v{a,b,c};
        sort(ALL(v));
        //如果最大的比剩下两个的和还大，那么只能取剩下两个的和的次数
        if(v[2]>v[0]+v[1])return v[0]+v[1];
        //否则一定可以一直两个两个拿，拿到空或者只剩一个
        else return (v[0]+v[1]+v[2])/2;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int a=3;
    int b=5;
    int c=7;
    auto ans=sol.maximumScore(a,b,c);
    DBG(ans);

    system("pause");
    return 0;
}
