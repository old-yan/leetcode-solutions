#include "utils.h"

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        int n=quality.size();
        double ratio[n];
        REP(i,n)ratio[i]=double(wage[i])/quality[i];
        int idx[n];
        iota(idx,idx+n,0);
        sort(idx,idx+n,[&](int x,int y){return ratio[x]<ratio[y];});
        priority_queue<int>Q;
        ll sum=0;
        REP(i,K){
            Q.push(quality[idx[i]]);
            sum+=quality[idx[i]];
        }
        double ans=ratio[idx[K-1]]*sum;
        FOR(i,K,n){
            sum+=quality[idx[i]];
            Q.push(quality[idx[i]]);
            sum-=Q.top();
            Q.pop();
            chmin(ans,ratio[idx[i]]*sum);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi quality{10,20,5};
    vi wage{70,50,30};
    int K=2;
    auto ans=sol.mincostToHireWorkers(quality,wage,K);
    DBG(ans);

    system("pause");
    return 0;
}
