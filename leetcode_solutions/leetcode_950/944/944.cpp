#include "utils.h"

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int m=strs[0].size();
        string pre(m,'a');
        for(string&str:strs){
            REP(i,m){
                if(str[i]<pre[i])pre[i]='z'+1;
                else pre[i]=str[i];
            }
        }
        return accumulate(ALL(pre),0,[](int cnt,char c){return cnt+(c>'z');});
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<string>strs{
        "cba","daf","ghi"
    };
    auto ans=sol.minDeletionSize(strs);
    DBG(ans);

    system("pause");
    return 0;
}
