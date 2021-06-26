#include "utils.h"

class Solution {
    int cnt[100000]={0};
    set<int>S;
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        REP(i,k)S.insert(i);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>Q;
        REP(i,arrival.size()){
            while(Q.size()&&Q.top().first<=arrival[i]){
                S.insert(Q.top().second);
                Q.pop();
            }
            if(S.empty())continue;
            auto it=S.lower_bound(i%k);
            if(it==S.end())it=S.begin();
            cnt[*it]++;
            Q.emplace(arrival[i]+load[i],*it);
            S.erase(it);
        }
        int Max=*max_element(cnt,cnt+k);
        vi ans;
        REP(i,k)if(cnt[i]==Max)ans.pb(i);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int k=3;
    vi arrival{1,2,3,4,5};
    vi load{5,2,3,3,3};
    auto ans=sol.busiestServers(k,arrival,load);
    DBGV(ans);

    system("pause");
    return 0;
}
