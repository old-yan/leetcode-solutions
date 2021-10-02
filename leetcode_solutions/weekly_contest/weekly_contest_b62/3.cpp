#include "utils.h"

class Solution {
public:
    //双指针找出最大的区间，使得区间内只需要改k次就能全部一致
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n=answerKey.size();
        int ans=0;
        //第一次遍历，试图让区间内全部为 'T'
        //枚举left作为左端，看right能延伸到多远
        for(int left=0,right=0,change=0;left<n;left++){
            //只要还在界内而且算上当前字符之后，不会超出预算，那就把当前字符算上
            for(;right<n&&(change<k||(change==k&&answerKey[right]=='T'));right++)if(answerKey[right]!='T')change++;
            //更新答案
            ans=max(ans,right-left);
            //将区间左端从区间里吐出去
            if(answerKey[left]!='T')change--;
        }
        //同上
        for(int left=0,right=0,change=0;left<n;left++){
            for(;right<n&&(change<k||(change==k&&answerKey[right]=='F'));right++)if(answerKey[right]!='F')change++;
            ans=max(ans,right-left);
            if(answerKey[left]!='F')change--;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string answerKey="TTFF";
    int k=2;
    auto ans=sol.maxConsecutiveAnswers(answerKey,k);
    DBG(ans);

    system("pause");
    return 0;
}