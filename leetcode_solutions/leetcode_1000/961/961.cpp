#include "utils.h"

class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        int cur,cnt=0;
        for(int a:A){
            if(cnt){
                if(cur==a)return a;
                else cnt--;
            }
            else{
                cur=a;
                cnt++;
            }
        }
        if(A[0]==A[2]||A[0]==A[3])return A[0];
        else return A[1];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi A{1,2,3,3};
    auto ans=sol.repeatedNTimes(A);
    DBG(ans);

    system("pause");
    return 0;
}
