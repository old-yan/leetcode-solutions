#include "utils.h"

class Solution {
public:
    //本题两重 for 循环就可以暴力搞定。
    //也可以写一个线性算法
    int maxDistance(vector<int>& colors) {
        //如果首尾不同，直接贪心选取
        if(colors.front()!=colors.back())
            return colors.size()-1;
        //如果首尾相同，设值为 value .不妨看看开头的 value 多还是结尾的 value 多
        int value=colors.front();
        int begin=0;
        while(colors[begin]==value)begin++;
        int end=0;
        while(colors[colors.size()-1-end]==value)end++;
        //把较少的那部分去掉，就可以转化为首尾不同的情况
        return colors.size()-min(begin,end)-1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<int>colors{1,1,1,6,1,1,1};
    auto ans=sol.maxDistance(colors);
    DBG(ans);

    system("pause");
    return 0;
}