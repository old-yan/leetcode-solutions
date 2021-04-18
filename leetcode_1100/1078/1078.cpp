#include "utils.h"

class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        auto v=split(text);
        vector<string>ans;
        for(int i=2;i<v.size();i++){
            if(v[i-2]==first&&v[i-1]==second)ans.pb(v[i]);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string text="alice is a good girl she is a good student";
    string first="a";
    string second="good";
    auto ans=sol.findOcurrences(text,first,second);
    DBGV(ans);

    system("pause");
    return 0;
}
