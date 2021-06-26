#include "utils.h"

class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans(n,'a');
        k-=n;
        REPR(i,n-1){
            if(!k)break;
            int j=min(k,25);
            ans[i]+=j;
            k-=j;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=3;
    int k=27;
    auto ans=sol.getSmallestString(n,k);
    DBG(ans);

    system("pause");
    return 0;
}
