#include "utils.h"

class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int m=req_skills.size(),n=people.size();
        unordered_map<string,int>M;
        REP(i,m)M[req_skills[i]]=i;
        int skill[n];
        REP(i,n){
            skill[i]=0;
            for(auto&s:people[i])skill[i]|=1<<M[s];
        }
        int dp[1<<m];
        pair<int,int>from[1<<m];
        memset(dp,0x3f,sizeof(dp));
        dp[0]=0;
        REP(i,n){
            REP(j,1<<m){
                if(chmin(dp[j|skill[i]],dp[j]+1)){
                    from[j|skill[i]]={j,i};
                }
            }
        }
        vi ans;
        for(int cur=(1<<m)-1;cur;cur=from[cur].first){
            ans.pb(from[cur].second);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<string> req_skills{"java","nodejs","reactjs"};
    vector<vector<string>>people{
        {"java"},
        {"nodejs"},
        {"nodejs","reactjs"}
    };
    auto ans=sol.smallestSufficientTeam(req_skills,people);
    DBG(ans);

    system("pause");
    return 0;
}
