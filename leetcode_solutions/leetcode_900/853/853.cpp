#include "utils.h"

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=position.size();
        int latestRight=-1;
        int ans=0;
        int idx[n];
        iota(idx,idx+n,0);
        sort(idx,idx+n,[&](int x,int y){return position[x]>position[y];});
        REP(i,n){
            if(latestRight<0||(ll)(target-position[latestRight])*speed[idx[i]]<(ll)(target-position[idx[i]])*speed[latestRight]){
                latestRight=idx[i];
                ans++;
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int target=12;
    vi position{10,8,0,5,3};
    vi speed{2,4,1,1,3};
    auto ans=sol.carFleet(target,position,speed);
    DBG(ans);

    system("pause");
    return 0;
}
