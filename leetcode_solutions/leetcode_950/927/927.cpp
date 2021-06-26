#include "utils.h"

class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int n=arr.size();
        vi idx;
        REP(i,n){
            if(arr[i]==1)idx.pb(i);
        }
        if(idx.empty())return {0,2};
        if(idx.size()%3)return {-1,-1};
        for(int k1=idx[0],k2=idx[idx.size()/3],k3=idx[idx.size()/3*2];k3<n;++k1,++k2,++k3){
            if(arr[k1]!=arr[k2]||arr[k2]!=arr[k3])return {-1,-1};
        }
        return {idx[idx.size()/3-1]+n-idx.back()-1,idx[idx.size()/3*2-1]+n-idx.back()};
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi arr{1,0,1,0,1};
    auto ans=sol.threeEqualParts(arr);
    DBGV(ans);

    system("pause");
    return 0;
}
