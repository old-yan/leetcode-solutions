#include "utils.h"

class Solution {
public:
    int reinitializePermutation(int n) {
        vi perm(n);
        iota(ALL(perm),0);
        int ans=0;
        do{
            vi arr(n);
            REP(i,n){
                if(i%2==0)arr[i]=perm[i/2];
                else arr[i]=perm[n/2+(i-1)/2];
            }
            perm.swap(arr);
            ans++;
        }while(!is_sorted(ALL(perm)));
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=2;
    auto ans=sol.reinitializePermutation(n);
    DBG(ans);

    system("pause");
    return 0;
}
