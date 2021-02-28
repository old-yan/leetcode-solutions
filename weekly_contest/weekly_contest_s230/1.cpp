#include "utils.h"

class Solution {
public:
    //简单模拟
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int idx;
        //先确定要check的下标
        if(ruleKey=="type")idx=0;
        else if(ruleKey=="color")idx=1;
        else idx=2;
        int ans=0;
        //遍历累加
        for(auto&item:items){
            if(item[idx]==ruleValue)ans++;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<vector<string>>items{
        {"phone","blue","pixel"},{"computer","silver","lenovo"},{"phone","gold","iphone"}
    };
    string ruleKey="color";
    string ruleValue="silver";
    auto ans=sol.countMatches(items,ruleKey,ruleValue);
    DBG(ans);

    system("pause");
    return 0;
}
