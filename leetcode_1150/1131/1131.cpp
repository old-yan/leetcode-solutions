#include "utils.h"

class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int n=arr1.size();
        int ans=0;
        REP(i,2){
            REP(j,2){
                int Max=INT_MIN,Min=INT_MAX;
                REP(l,n){
                    int sum=0;
                    if(i)sum+=arr1[l];
                    else sum-=arr1[l];
                    if(j)sum+=arr2[l];
                    else sum-=arr2[l];
                    sum+=l;
                    chmin(Min,sum);
                    chmax(Max,sum);
                }
                chmax(ans,Max-Min);
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi arr1{1,2,3,4};
    vi arr2{-1,4,5,6};
    auto ans=sol.maxAbsValExpr(arr1,arr2);
    DBG(ans);

    system("pause");
    return 0;
}
