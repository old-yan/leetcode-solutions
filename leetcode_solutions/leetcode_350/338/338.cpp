#include "utils.h"

class Solution {
public:
    vector<int> countBits(int num) {
        map<int,int>M;
        REP(i,20){
            M[1<<i]=i-1;
        }
        vi ans(num+1,0);
        int cur=0;
        REP(i,num+1){
            ans[i]=cur;
            int j=i^0xffffffff;
            int k=j&(-j);
            cur-=M[k];
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int num=10;
    auto ans=sol.countBits(num);
    DBGV(ans);

    system("pause");
    return 0;
}
