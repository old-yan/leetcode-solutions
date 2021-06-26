#include "utils.h"

class Solution {
public:
    int storeWater(vector<int>& bucket, vector<int>& vat) {
        if(accumulate(ALL(vat),0ll)==0)return 0;
        priority_queue<tuple<int,int,int>>Q;
        REP(i,bucket.size())Q.emplace(bucket[i]?(vat[i]+bucket[i]-1)/bucket[i]:0x3f3f3f3f,bucket[i],vat[i]);
        int ans=get<0>(Q.top()),cur=0;
        while(true){
            auto [a,b,c]=Q.top();
            Q.pop();
            if(!chmin(a,(c+b)/(b+1)))break;
            b++;
            cur++;
            Q.emplace(a,b,c);
            chmin(ans,cur+get<0>(Q.top()));
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi bucket{1,3};
    vi vat{6,8};
    auto ans=sol.storeWater(bucket,vat);
    DBG(ans);

    system("pause");
    return 0;
}
