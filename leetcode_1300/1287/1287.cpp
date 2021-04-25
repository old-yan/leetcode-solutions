#include "utils.h"

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        for(int i=0,j=0;i<arr.size();i=j){
            while(j<arr.size()&&arr[j]==arr[i])j++;
            if(j-i>arr.size()/4)return arr[i];
        }
        return -1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi arr{1,2,2,6,6,6,6,7,10};
    auto ans=sol.findSpecialInteger(arr);
    DBG(ans);

    system("pause");
    return 0;
}
