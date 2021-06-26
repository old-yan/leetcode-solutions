#include "utils.h"

class Solution {
    int dif[5001];
public:
    int tallestBillboard(vector<int>& rods) {
        int n=rods.size();
        int sum=accumulate(ALL(rods),0);
        memset(dif,0x3f,sizeof(dif));
        dif[sum]=0;
        for(int a:rods){
            REP(i,sum+1){
                if(i+a<=sum)chmin(dif[i],dif[i+a]+a);
                if(i+a*2<=sum)chmin(dif[i],dif[i+a*2]);
            }
        }
        return (sum-dif[0])/2;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi rods{1,2,3,6};
    auto ans=sol.tallestBillboard(rods);
    DBG(ans);

    system("pause");
    return 0;
}
