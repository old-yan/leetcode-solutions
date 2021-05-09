#include "utils.h"

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int cnt[k];
        memset(cnt,0,sizeof(cnt));
        for(int a:arr){
            if(a<0)a+=110000000-110000000%k;
            cnt[a%k]++;
        }
        if(cnt[0]%2)return false;
        FOR(i,1,k/2+1){
            if(cnt[i]!=cnt[k-i])return false;
        }
        return true;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi arr{1,2,3,4,5,10,6,7,8,9};
    int k=5;
    auto ans=sol.canArrange(arr,k);
    DBG(ans);

    system("pause");
    return 0;
}
