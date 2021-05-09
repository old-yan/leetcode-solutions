#include "utils.h"

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        unordered_map<int,int>watered;
        set<int>idle;
        REP(i,rains.size()){
            if(rains[i]>0){
                if(watered.count(rains[i])){
                    auto it=idle.lower_bound(watered[rains[i]]);
                    if(it==idle.end())return {};
                    rains[*it]=rains[i];
                    idle.erase(it);
                }
                watered[rains[i]]=i;
                rains[i]=-1;
            }
            else{
                idle.insert(i);
            }
        }
        for(int idx:idle)rains[idx]=1;
        return rains;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi rains{1,2,0,2,3,0,1};
    auto ans=sol.avoidFlood(rains);
    DBGV(ans);

    system("pause");
    return 0;
}
