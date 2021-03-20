#include "utils.h"

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        queue<int>Q[32];
        unordered_set<int>S:
        REP(i,arr.size()){
            if(!arr[i])S.insert(0);
            REP(j,32){
                if(arr[i]>>j&1)Q[j].push(i);
            }
        }
        REP(i,arr.size()){
            vi v;
            REP(j,32)if(Q[j].size())v.pb(Q[j].front());
            sort(ALL(v));
            v.resize(unique(ALL(v))-v.begin());
            int mask=0;
            for(int j:v){
                mask|=arr[j];
                S.insert(mask);
            }
            REP(j,32){
                if(arr[i]>>j&1)Q[j].pop();
            }
        }
        return S.size();
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi arr{1,2,4};
    auto ans=sol.subarrayBitwiseORs(arr);
    DBG(ans);

    system("pause");
    return 0;
}
