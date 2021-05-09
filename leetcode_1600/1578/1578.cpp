#include "utils.h"

class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        auto next=next_different(s);
        int ans=0;
        for(int i=0;i<s.size();i=next[i]){
            int sum=0,Max=INT_MIN;
            FOR(j,i,next[i]){
                sum+=cost[j];
                chmax(Max,cost[j]);
            }
            ans+=sum-Max;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="abaac";
    vi cost{1,2,3,4,5};
    auto ans=sol.minCost(s,cost);
    DBG(ans);

    system("pause");
    return 0;
}
