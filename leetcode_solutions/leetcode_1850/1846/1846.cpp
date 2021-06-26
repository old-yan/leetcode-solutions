#include "utils.h"

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(ALL(arr));
        arr[0]=1;
        int cur=0;
        for(int a:arr){
            if(a>cur+1){
                cur++;
            }
            else cur=a;
        }
        return cur;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi arr{2,2,1,2,1};
    auto ans=sol.maximumElementAfterDecrementingAndRearranging(arr);
    DBG(ans);

    system("pause");
    return 0;
}
