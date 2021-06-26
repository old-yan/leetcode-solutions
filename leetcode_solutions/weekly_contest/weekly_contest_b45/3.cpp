#include "utils.h"

class Solution {
public:
    int minimumLength(string s) {
        if(s.size()==1)return 1;
        int i=0,j=s.size()-1;
        for(;s[i]==s[j];){
            //用变量next_differ_i找到和i处字符不同的下一个位置
            int next_differ_i;
            for(next_differ_i=i+1;s[next_differ_i]==s[i];next_differ_i++);
            //用变量prev_differ_j找到和j处字符不同的上一个位置
            int prev_differ_j;
            for(prev_differ_j=j-1;prev_differ_j>=0&&s[prev_differ_j]==s[j];prev_differ_j--);
            //如果擦肩而过，说明i和j已经处于相同的一段区间内
            if(next_differ_i>prev_differ_j){
                //如果区间长为1，无法分成前后两部分，消不掉
                if(j==i)return 1;
                //如果区间长大于1，可以消掉
                else return 0;
            }
            else{
                i=next_differ_i;
                j=prev_differ_j;
            }
        }
        //当s[i]!=s[j]时，无法继续消除
        return j-i+1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="aabccabba";
    auto ans=sol.minimumLength(s);
    DBG(ans);

    system("pause");
    return 0;
}
