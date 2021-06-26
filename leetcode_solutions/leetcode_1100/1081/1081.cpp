#include "utils.h"

class Solution {
public:
    string smallestSubsequence(string s) {
        string ans;
        int cnt[26]={0};
        bool used[26]={0};
        for(char c:s)cnt[c-'a']++;
        for(char c:s){
            if(!used[c-'a']){
                while(ans.size()&&ans.back()>=c&&cnt[ans.back()-'a']){
                    used[ans.back()-'a']=false;
                    ans.pop_back();
                }
                used[c-'a']=true;
                ans.pb(c);
            }
            cnt[c-'a']--;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="bcbcbcababa";
    auto ans=sol.smallestSubsequence(s);
    DBG(ans);

    system("pause");
    return 0;
}
