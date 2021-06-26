#include "utils.h"

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int cur=0;
        for(int a:arr){
            while(cur+1!=a){
                if(!--k)return cur+1;
                cur++;
            }
            cur++;
        }
        return cur+k;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi arr{2,3,4,7,11};
    int k=5;
    auto ans=sol.findKthPositive(arr,k);
    DBG(ans);

    system("pause");
    return 0;
}
