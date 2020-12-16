#include "utils.h"

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int a[50]={0};
        a[0]=1;
        REP(i,rowIndex){
            FORR(j,i+1,1){
                a[j]+=a[j-1];
            }
        }
        return vi(a,a+rowIndex+1);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int rowIndex=10;
    auto ans=sol.getRow(rowIndex);
    DBGV(ans);

    system("pause");
    return 0;
}
