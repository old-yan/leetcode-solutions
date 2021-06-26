#include "utils.h"

class Solution {
public:
    string arrangeWords(string text) {
        auto v=split(text,' ');
        v[0][0]=tolower(v[0][0]);
        stable_sort(ALL(v),[](const string&x,const string&y){
            return x.size()<y.size();
        });
        v[0][0]=toupper(v[0][0]);
        string ans=v[0];
        FOR(i,1,v.size())ans+=" "+v[i];
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string text="Leetcode is cool";
    auto ans=sol.arrangeWords(text);
    DBG(ans);

    system("pause");
    return 0;
}
