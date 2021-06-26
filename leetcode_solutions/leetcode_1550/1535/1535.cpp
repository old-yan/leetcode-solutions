#include "utils.h"

class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int Maxidx=0;
        REP(i,arr.size()){
            if(arr[i]>arr[Maxidx])Maxidx=i;
            if(i-max(Maxidx,1)+1>=k)return arr[Maxidx];
        }
        return arr[Maxidx];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi arr{2,1,3,5,4,6,7};
    int k=2;
    auto ans=sol.getWinner(arr,k);
    DBG(ans);

    system("pause");
    return 0;
}
