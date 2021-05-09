#include "utils.h"

class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int ans=0;
        REP(k,arr.size()){
            REP(j,k)if(abs(arr[j]-arr[k])<=b){
                REP(i,j){
                    ans+=abs(arr[i]-arr[j])<=a&&abs(arr[i]-arr[k])<=c;
                }
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi arr{3,0,1,1,9,7};
    int a=7;
    int b=2;
    int c=3;
    auto ans=sol.countGoodTriplets(arr,a,b,c);
    DBG(ans);

    system("pause");
    return 0;
}
