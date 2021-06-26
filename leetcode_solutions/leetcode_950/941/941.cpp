#include "utils.h"

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int i=0,j=arr.size()-1;
        while(i+1<arr.size()&&arr[i+1]>arr[i])i++;
        while(j-1>=0&&arr[j-1]>arr[j])j--;
        return i==j&&i&&i<arr.size();
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi arr{0,3,2,1};
    auto ans=sol.validMountainArray(arr);
    DBG(ans);

    system("pause");
    return 0;
}
