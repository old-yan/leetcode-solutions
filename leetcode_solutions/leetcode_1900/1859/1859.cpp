#include "utils.h"

class Solution {
public:
    string sortSentence(string s) {
        auto v=split(s);
        vector<string>ans(v.size());
        for(auto&a:v){
            ans[a.back()-'0'-1]=a.substr(0,a.size()-1);
        }
        FOR(i,1,ans.size()){
            ans[0]+=" "+ans[i];
        }
        return ans[0];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="is2 sentence4 This1 a3";
    auto ans=sol.sortSentence(s);
    DBG(ans);

    system("pause");
    return 0;
}
