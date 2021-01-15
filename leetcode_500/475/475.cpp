#include "utils.h"

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(ALL(houses));
        sort(ALL(heaters));
        heaters.insert(heaters.begin(),INT_MIN);
        heaters.pb(INT_MAX);
        ll ans=0;
        for(int i=0,j=0;i<houses.size();i++){
            while(heaters[j]<houses[i])j++;
            chmax(ans,min((ll)houses[i]-heaters[j-1],(ll)heaters[j]-houses[i]));
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi houses{1,2,3,4};
    vi heaters{1,4};
    auto ans=sol.findRadius(houses,heaters);
    DBG(ans);

    system("pause");
    return 0;
}
