#include "utils.h"

class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        unordered_map<string,int>M{
            {"type",0},
            {"color",1},
            {"name",2}
        };
        int index=M[ruleKey];
        int ans=0;
        for(auto&item: items){
            if(item[index]==ruleValue)ans++;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<vector<string>>items={
        {"phone","blue","pixel"},
        {"computer","silver","lenovo"},
        {"phone","gold","iphone"}
    };
    string ruleKey="color";
    string ruleValue="silver";
    auto ans=sol.countMatches(items,ruleKey,ruleValue);
    DBG(ans);

    system("pause");
    return 0;
}
