#include "Heap.h"
#include "utils.h"

class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vi idx(n);
        iota(ALL(idx),0);
        sort(ALL(idx),[&](int x,int y){
            return efficiency[x]>efficiency[y];
        });
        Heap<int>H([&](int x,int y){return speed[x]>speed[y];});
        ll sum=0;
        ll ans=0;
        for(int i=0;i<n;i++){
            int j=idx[i];
            sum+=speed[j];
            H.push(j);
            if(H.size()>k){
                sum-=speed[H.top()];
                H.pop();
            }
            chmax(ans,sum*efficiency[j]);
        }
        return ans%MOD;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=6;
    vi speed{2,10,3,1,5,8};
    vi efficiency{5,4,3,9,7,2};
    int k=2;
    auto ans=sol.maxPerformance(n,speed,efficiency,k);
    DBG(ans);

    system("pause");
    return 0;
}
