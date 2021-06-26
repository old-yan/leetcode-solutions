#include "utils.h"

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans=0;
        for(int i=0,j;i<arr.size();i=j){
            int Max=arr[i];
            for(j=i+1;j<=Max;j++){
                chmax(Max,arr[j]);
            }
            ans++;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi arr{4,3,2,1,0};
    auto ans=sol.maxChunksToSorted(arr);
    DBG(ans);

    system("pause");
    return 0;
}
