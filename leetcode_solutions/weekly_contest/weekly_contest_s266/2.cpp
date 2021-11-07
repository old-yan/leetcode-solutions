#include "utils.h"

class Solution {
public:
    //如果要对每个子串计数元音字符，时间复杂度显然太大
    //可以对每个元音字符计数它会被几个子串所包含
    long long countVowels(string word) {
        bool isVowel[128]={0};
        for(char c:{'a','e','i','o','u'}){
            isVowel[c]=true;
        }
        long long ans=0;
        for(int i=0;i<word.size();i++){
            //非元音字符忽略
            if(!isVowel[word[i]])continue;
            //对于元音字符，找出它所在的子串的开始下标有几种可能
            int possible_start=i+1;
            //对于元音字符，找出它所在的子串的结尾下标有几种可能
            int possible_end=word.size()-i;
            ans+=(long long)possible_start*possible_end;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string word="noosabasboosa";
    auto ans=sol.countVowels(word);
    DBG(ans);

    system("pause");
    return 0;
}