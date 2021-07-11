#include "utils.h"

class Solution {
public:
    //做这道题，要意识到可能的答案只有 26*26 种
    //枚举每一个字符作为中间字符，然后枚举两侧字符的26种可能
    int countPalindromicSubsequence(string s) {
        bool appear[26][26]={0};
        //记录每一个字符的第一次出现位置，最后一次出现位置
        int first[26],last[26];
        memset(first,0x3f,sizeof(first));
        memset(last,0xff,sizeof(last));
        for(int i=0;i<s.size();i++){
            chmin(first[s[i]-'a'],i);
            chmax(last[s[i]-'a'],i);
        }
        int ans=0;
        //枚举中心
        for(int i=0;i<s.size();i++){
            //枚举两侧
            for(int j=0;j<26;j++)if(!appear[s[i]-'a'][j]){
                if(first[j]<i&&last[j]>i){
                    appear[s[i]-'a'][j]=true;
                    ans++;
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

    string s="aabca";
    auto ans=sol.countPalindromicSubsequence(s);
    DBG(ans);

    system("pause");
    return 0;
}
