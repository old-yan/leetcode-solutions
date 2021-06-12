#include "utils.h"

class Solution {
public:
    string reverseWords(string s) {
        auto v=split(s);
        reverse(ALL(v));
        string ans;
        for(auto&a:v){
            if(ans.size())ans+=" ";
            ans+=a;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="the sky is blue";
    auto ans=sol.reverseWords(s);
    DBG(ans);

    system("pause");
    return 0;
}
