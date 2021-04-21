#include "utils.h"

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vi cnt(26,0);
        for(char c:chars)cnt[c-'a']++;
        int ans=0;
        for(string&s:words){
            vi cur(26,0);
            for(char c:s)cur[c-'a']++;
            bool flag=true;
            REP(i,26){
                if(cur[i]>cnt[i]){
                    flag=false;
                    break;
                }
            }
            if(flag)ans+=s.size();
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<string>words{"cat","bt","hat","tree"};
    string chars="atach";
    auto ans=sol.countCharacters(words,chars);
    DBG(ans);

    system("pause");
    return 0;
}
