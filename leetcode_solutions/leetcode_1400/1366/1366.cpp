#include "utils.h"

class Solution {
    int cnt[26][26]={0};
public:
    string rankTeams(vector<string>& votes) {
        int m=votes.size(),n=votes[0].size();
        for(string&v:votes){
            REP(i,n)cnt[v[i]-'A'][i]++;
        }
        string ans=votes[0];
        sort(ALL(ans),[&](char x,char y){
            REP(i,26)if(cnt[x-'A'][i]!=cnt[y-'A'][i])return cnt[x-'A'][i]>cnt[y-'A'][i];
            return x<y;
        });
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<string> votes{"ABC","ACB","ABC","ACB","ACB"};
    auto ans=sol.rankTeams(votes);
    DBG(ans);

    system("pause");
    return 0;
}
