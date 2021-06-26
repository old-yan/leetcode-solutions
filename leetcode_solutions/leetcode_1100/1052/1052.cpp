#include "utils.h"

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int cnt=0;
        REP(i,customers.size()){
            if(!grumpy[i])cnt+=customers[i];
        }
        REP(i,X){
            if(grumpy[i])cnt+=customers[i];
        }
        int ans=cnt;
        FOR(i,X,customers.size()){
            if(grumpy[i])cnt+=customers[i];
            if(grumpy[i-X])cnt-=customers[i-X];
            chmax(ans,cnt);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi customers{1,0,1,2,1,1,7,5};
    vi grumpy{0,1,0,1,0,1,0,1};
    int X=3;
    auto ans=sol.maxSatisfied(customers,grumpy,X);
    DBG(ans);

    system("pause");
    return 0;
}
