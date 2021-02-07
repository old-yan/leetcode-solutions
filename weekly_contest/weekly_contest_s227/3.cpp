#include "utils.h"

class Solution {
public:
    //贪心问题，每次首先看当前两个字母谁大，取谁
    //如果当前两个字母打平手，就看两个字母后面的字母谁大，也就是谁背后能释放的潜力大就取谁
    string largestMerge(string word1, string word2) {
        string ans;
        int i1=0,i2=0;
        while(i1<word1.size()&&i2<word2.size()){
            //strcmp返回正值，表示挨个比较，前者大于后者
            if(strcmp(&word1[i1],&word2[i2])>=0)ans.pb(word1[i1++]);
            else ans.pb(word2[i2++]);
        }
        //如果word2空了，将word1残部加进去
        ans+=word1.substr(i1);
        //如果word1空了，将word2残部加进去
        ans+=word2.substr(i2);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string word1="abcabc";
    string word2="abdcaba";
    auto ans=sol.largestMerge(word1,word2);
    DBG(ans);

    system("pause");
    return 0;
}
