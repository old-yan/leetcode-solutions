#include "utils.h"

class Solution {
public:
    int findLucky(vector<int>& arr) {
        sort(ALLR(arr));
        for(int i=0,j=0;i<arr.size();i=j){
            for(j=i+1;j<arr.size()&&arr[j]==arr[i];j++);
            if(j-i==arr[i])return arr[i];
        }
        return -1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi arr{1,2,2,3,3,3};
    auto ans=sol.findLucky(arr);
    DBG(ans);

    system("pause");
    return 0;
}
