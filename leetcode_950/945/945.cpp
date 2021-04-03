#include "utils.h"

class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        sort(ALL(A));
        int ans=0;
        int now=0;
        int pre=-1;
        for(int a:A){
            while(now&&pre<a){
                ans+=now--;
                pre++;
            }
            if(pre<a){
                pre=a;
            }
            else{
                now++;
            }
        }
        while(now){
            ans+=now--;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi A{3,2,1,2,1,7};
    auto ans=sol.minIncrementForUnique(A);
    DBG(ans);

    system("pause");
    return 0;
}
