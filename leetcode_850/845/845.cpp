#include "utils.h"

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n=arr.size();
        int up[n];
        int down[n];
        REP(i,n){
            up[i]=i&&arr[i]>arr[i-1]?up[i-1]+1:1;
        }
        REPR(i,n-1){
            down[i]=i+1<n&&arr[i]>arr[i+1]?down[i+1]+1:1;
        }
        int ans=0;
        REP(i,n){
            if(up[i]>1&&down[i]>1){
                chmax(ans,up[i]+down[i]-1);
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi arr{2,1,4,7,3,2,5};
    auto ans=sol.longestMountain(arr);
    DBG(ans);

    system("pause");
    return 0;
}
