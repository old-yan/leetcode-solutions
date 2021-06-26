#include "utils.h"

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vi rnk(1001,INT_MAX);
        REP(i,arr2.size()){
            rnk[arr2[i]]=i;
        }
        sort(ALL(arr1),[&](int x,int y){
            if(rnk[x]!=rnk[y])return rnk[x]<rnk[y];
            else return x<y;
        });
        return arr1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi arr1{2,3,1,3,2,4,6,7,9,2,19};
    vi arr2{2,1,4,3,9,6};
    auto ans=sol.relativeSortArray(arr1,arr2);
    DBGV(ans);

    system("pause");
    return 0;
}
