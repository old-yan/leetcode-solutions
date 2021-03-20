#include "utils.h"

class Solution {
public:
    //本题与力扣330题相似
    //贪心思维：将所有原材料从小到大排列，然后依次判断
    //如果现在我可以取到0~can范围内的所有数，那么面前的这个原材料必须要<=can+1
    //因为，如果面前的原材料>can+1，那么我们没有任何方法获取can+1这个数，出现断层。
    //假如面前的原材料<=can+1，设其为a，那么：
    //  1.我们可以获取0~can范围内的所有数；
    //  2.我们可以获取can+1-a~can范围内的所有数，再搭配个a，就是可以获取can+1~can+a范围内的所有数。
    //综合以上两条，推出我们可以获取0~can+a范围内的所有数
    //然后继续面对下一个原材料。
    int getMaximumConsecutive(vector<int>& coins) {
        sort(coins.begin(),coins.end());
        int can=0;
        for(int a:coins){
            if(a>can+1)break;
            can+=a;
        }
        return can+1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi coins{1,4,10,3,1};
    auto ans=sol.getMaximumConsecutive(coins);
    DBG(ans);

    system("pause");
    return 0;
}
