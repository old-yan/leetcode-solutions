#include "utils.h"

class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        int num[26]={0};
        for(char c:licensePlate){
            if(islower(c))num[c-'a']++;
            else if(isupper(c))num[c-'A']++;
        }
        string ans(16,' ');
        for(string&word:words){
            int cnt[26]={0};
            for(char c:word){
                if(islower(c))cnt[c-'a']++;
                else if(isupper(c))cnt[c-'A']++;
            }
            bool contain=true;
            REP(i,26){
                if(cnt[i]<num[i])contain=false;
            }
            if(contain&&word.size()<ans.size())ans=word;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string licensePlate="1s3 PSt";
    vector<string>words{"step","steps","stripe","stepple"};
    auto ans=sol.shortestCompletingWord(licensePlate,words);
    DBG(ans);

    system("pause");
    return 0;
}
