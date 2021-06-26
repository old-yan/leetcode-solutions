#include "utils.h"

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<pair<string,string>>copy;
        for(auto&s:strs)copy.emplace_back(s,s);
        for(auto&[a,b]:copy)sort(ALL(a));
        sort(ALL(copy));
        vector<vector<string>>ans;
        for(int i=0,j;i<copy.size();i=j){
            ans.pb({});
            for(j=i;j<copy.size()&&copy[j].first==copy[i].first;j++){
                ans.back().emplace_back(copy[j].second);
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<string>strs{
        "eat", "tea", "tan", "ate", "nat", "bat"
    };
    auto ans=sol.groupAnagrams(strs);
    DBGVV(ans);

    system("pause");
    return 0;
}
