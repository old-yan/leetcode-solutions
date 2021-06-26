#include "utils.h"

class Solution {
    bool isVowel[128]={0};
public:
    int maxVowels(string s, int k) {
        string Vowel="aeiou";
        for(char c:Vowel)isVowel[c]=true;
        int ans=0;
        for(int left=0,right=0,cnt=0;right<s.size();){
            while(right<left+k)cnt+=isVowel[s[right++]];
            chmax(ans,cnt);
            cnt-=isVowel[s[left++]];
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="abciiidef";
    int k=3;
    auto ans=sol.maxVowels(s,k);
    DBG(ans);

    system("pause");
    return 0;
}
