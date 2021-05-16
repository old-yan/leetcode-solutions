#include "utils.h"

class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int n=encoded.size()+1;
        int all=0;
        REP(i,n)all^=i+1;
        int sum=0;
        for(int i=1;i<n;i+=2){
            sum^=encoded[i];
        }
        vi ans{sum^all};
        for(int a:encoded){
            ans.pb(ans.back()^a);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi encoded{6,5,4,6};
    auto ans=sol.decode(encoded);
    DBGV(ans);

    system("pause");
    return 0;
}
