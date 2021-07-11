#include "utils.h"

class Solution {
public:
    //分情况讨论
    bool sumGame(string num) {
        int n=num.size(),question1=0,question2=0;
        for(int i=0;i<n/2;i++)question1+=num[i]=='?';
        for(int i=n/2;i<n;i++)question2+=num[i]=='?';
        //如果有奇数个问号，那么主动权在alice手里，必胜
        if((question1+question2)%2)return true;
        //如果有偶数个问号，不妨简化问题：
        //  前半段和后半段相等 <--> 前半段减去后半段的差等于0
        //  所有的问号预设为 4.5 ，那么之后确定问号的值，就是在 [-4.5 , 4.5] 之间进行选择
        double dif=4.5*question1-4.5*question2;
        for(int i=0;i<n/2;i++)if(isdigit(num[i]))dif+=num[i]-'0';
        for(int i=n/2;i<n;i++)if(isdigit(num[i]))dif-=num[i]-'0';
        //如果 dif 为零，先手选 [-4.5, 4.5] 内的任意数，后手选择相反数，后手必胜
        //如果 dif 不为零
        //  如果dif为正，那么先手每次都选 4.5, 后手被迫选择 -4.5，总和永远为正
        //  如果dif为负，那么先手每次都选 -4.5, 后手被迫选择 4.5，总和永远为负
        //  所以先手必胜
        return dif!=0;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string num="?3295???";
    auto ans=sol.sumGame(num);
    DBG(ans);

    system("pause");
    return 0;
}
