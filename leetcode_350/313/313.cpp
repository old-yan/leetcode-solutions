#include "utils.h"

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int ans[n];
        int idx=0;
        ans[idx++]=1;
        int step[primes.size()];
        int res[primes.size()];
        REP(i,primes.size()){
            step[i]=0;
            res[i]=ans[step[i]]*primes[i];
        }
        auto comp=[&](int x,int y){return res[x]>res[y];};
        priority_queue<int,deque<int>,decltype(comp)>Q(comp);
        REP(i,primes.size())Q.push(i);
        while(idx<n){
            auto a=Q.top();
            Q.pop();
            if(res[a]>ans[idx-1]){
                ans[idx++]=res[a];
            }
            step[a]++;
            res[a]=ans[step[a]]*primes[a];
            Q.push(a);
        }
        return ans[n-1];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=12;
    vi primes{2,7,13,19};
    auto ans=sol.nthSuperUglyNumber(n,primes);
    DBG(ans);

    system("pause");
    return 0;
}
