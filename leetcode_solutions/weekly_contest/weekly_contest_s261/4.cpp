#include "utils.h"

class Solution {
public:
    //本质类似于用单调栈做最小子串
    string smallestSubsequence(string s, int k, char letter, int repetition) {
        int cnt=0;
        for(char c:s)if(c==letter)cnt++;
        //drop表示最多可以扔掉几个letter
        int drop=cnt-repetition;
        //have表示现在有几个非letter字符
        int have=0;
        string ans;
        int n=s.size();
        for(int i=0;i<n;i++){
            //视情况决定是否弹出最后一个字符
            while(ans.size()){
                if(ans.back()==letter){
                    //如果扔掉之后就凑不够k个，那就不能扔
                    if(ans.size()+n-1-i<k)break;
                    //如果扔掉之后凑不够repetition个letter，那就不能扔
                    if(drop==0)break;
                    //如果尾字符并不比s[i]大，那就不能扔
                    if(ans.back()<=s[i])break;
                    //可以扔
                    ans.pop_back(),drop--;
                }
                else{
                    //如果扔掉之后就凑不够k个，那就不能扔
                    if(ans.size()+n-1-i<k)break;
                    //如果尾字符并不比s[i]大，那就不能扔
                    if(ans.back()<=s[i])break;
                    //可以扔
                    ans.pop_back(),have--;
                }
            }
            //视情况决定是否拼接 s[i]
            if(s[i]==letter){
                //如果拼接之后长度不会超，那就拼接
                if(ans.size()<k)ans+=s[i];
                else drop--;
            }
            else{
                //如果拼接之后长度不会超，那就拼接
                if(have+repetition<k and ans.size()<k){
                    ans+=s[i];
                    if(s[i]!=letter)have++;
                }
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="leetcode";
    int k=4;
    char letter='e';
    int repetition=2;
    auto ans=sol.smallestSubsequence(s,k,letter,repetition);
    DBG(ans);

    system("pause");
    return 0;
}