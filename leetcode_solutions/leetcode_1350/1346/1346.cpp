#include "utils.h"

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int>S;
        for(int a:arr){
            if(S.count(a*2)||(a%2==0&&S.count(a/2)))return true;
            S.emplace(a);
        }
        return false;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi arr{10,2,5,3};
    auto ans=sol.checkIfExist(arr);
    DBG(ans);

    system("pause");
    return 0;
}
