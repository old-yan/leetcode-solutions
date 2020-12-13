#include "utils.h"

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int jinwei=1;
        REPR(i,digits.size()-1){
            digits[i]+=jinwei;
            jinwei=digits[i]>9;
            if(jinwei)digits[i]-=10;
        }
        if(jinwei){
            digits.insert(digits.begin(),1);
        }
        return digits;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi digits{9};
    auto ans=sol.plusOne(digits);
    DBGV(ans);

    system("pause");
    return 0;
}
