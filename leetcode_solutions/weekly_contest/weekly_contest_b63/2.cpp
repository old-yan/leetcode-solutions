#include "utils.h"

class Solution {
public:
    //由题意可知，Alice 和 Bob 各玩各的，根本不会互相干扰
    //而且 Alice 和 Bob 各自能走的步骤是固定的，与顺序无关
    //所以统计出 Alice 和 Bob 各自能走的步数，只有先手能走的步数比后手多，先手才能赢；反之后手赢
    bool winnerOfGame(string colors) {
        int a=0,b=0;
        for(int i=0,j;i<colors.size();i=j){
            for(j=i+1;colors[j]==colors[i];j++);
            int len=j-i;
            if(len<2)continue;
            if(colors[i]=='A'){
                a+=len-2;
            }
            else b+=len-2;
        }
        return a>b;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string colors="ABBBBBBBAAA";
    auto ans=sol.winnerOfGame(colors);
    DBG(ans);

    system("pause");
    return 0;
}