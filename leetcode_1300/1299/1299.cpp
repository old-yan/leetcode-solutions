#include "utils.h"

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int Max=-1;
        for(auto it=arr.rbegin();it!=arr.rend();++it){
            if(!chmax(*it,Max))swap(*it,Max);
        }
        return arr;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi arr{17,18,5,4,6,1};
    auto ans=sol.replaceElements(arr);
    DBG(ans);

    system("pause");
    return 0;
}
