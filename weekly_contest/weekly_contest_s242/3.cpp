#include "utils.h"

class Solution {
public:
    //使用差分思想，每当对一个区间进行跳跃许可时，在区间头差分+1，区间尾部差分减一
    //这样，只要一路把差分值进行累加，当前的值就表示现在手握几张许可证
    bool canReach(string s, int minJump, int maxJump) {
        ll dp[220000]={1,-1};
        int cur=0;
        for(int i=0;i<s.size();i++){
            cur+=dp[i];
            //如果我是字符'0'且手握通行证，那我可以继续往后发放通行证
            if(s[i]=='0'&&cur){
                dp[i+minJump]++;
                dp[i+maxJump+1]--;
            }
        }
        return s.back()=='0'&&cur;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="011010";
    int minJump=2;
    int maxJump=3;
    auto ans=sol.canReach(s,minJump,maxJump);
    DBG(ans);

    system("pause");
    return 0;
}
