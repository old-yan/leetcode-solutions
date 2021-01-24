#include "utils.h"

class Solution {
public:
    int minCharacters(string a, string b) {
        zkwTree T1(26),T2(26);
        //将字符串a的字母分布存入T1
        for(char c:a)T1.step(c-'a');
        //将字符串b的字母分布存入T2
        for(char c:b)T2.step(c-'a');
        int ans=INT_MAX;
        //遍历字母，计算将a、b全部变成某字母的步数
        REP(c,26){
            chmin(ans,int(a.size()+b.size()-T1[c]-T2[c]));
        }
        //遍历字母，计算将a全部变到该字母之前，将b全部变到该字母（及）之后的步数
        FOR(i,1,26){
            chmin(ans,int(T1(i,25)+T2(0,i-1)));
        }
        //遍历字母，计算将b全部变到该字母之前，将a全部变到该字母（及）之后的步数
        FOR(i,1,26){
            chmin(ans,int(T2(i,25)+T1(0,i-1)));
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string a="dabadd";
    string b="cda";
    auto ans=sol.minCharacters(a,b);
    DBG(ans);

    system("pause");
    return 0;
}
