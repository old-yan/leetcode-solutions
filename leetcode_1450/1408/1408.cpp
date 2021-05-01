#include "utils.h"

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int n=words.size();
        bool flag[n];
        fill(flag,flag+n,false);
        REP(i,n){
            REP(j,n)if(words[i].size()<words[j].size()){
                if(words[i]==words[j].substr(0,words[i].size())||int(words[j].find(words[i],1))>=0){
                    flag[i]=true;
                    break;
                }
            }
        }
        vector<string>ans;
        REP(i,n)if(flag[i])ans.pb(words[i]);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<string>words{"mass","as","hero","superhero"};
    auto ans=sol.stringMatching(Words);
    DBGV(ans);

    system("pause");
    return 0;
}
