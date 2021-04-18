#include "Regex.h"
#include "utils.h"

class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool>ans(queries.size());
        string p="[a-z]*";
        for(char c:pattern){
            p+=c;
            p+="[a-z]*";
        }
        auto re=Regex(p.c_str());
        REP(i,queries.size()){
            ans[i]=re.match(queries[i].c_str());
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<string>queries{
        "FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"
    };
    string pattern="FB";
    auto ans=sol.camelMatch(queries,pattern);
    DBGV(ans);

    system("pause");
    return 0;
}
