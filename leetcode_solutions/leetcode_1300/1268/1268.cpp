#include "utils.h"

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>>ans(searchWord.size());
        sort(ALL(products));
        for(string&s:products){
            int end=min(s.size(),searchWord.size());
            REP(i,end){
                if(s[i]!=searchWord[i])break;
                if(ans[i].size()<3)ans[i].pb(s);
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<string>products{
        "mobile","mouse","moneypot","monitor","mousepad"
    };
    string searchWord="mouse";
    auto ans=sol.suggestedProducts(products,searchWord);
    DBGVV(ans);

    system("pause");
    return 0;
}
