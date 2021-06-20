#include "utils.h"

class Solution {
public:
    vector<string> findLongestSubarray(vector<string>& array) {

    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<string>array{
        "A","1","B","C","D","2","3","4","E","5","F","G","6","7","H","I","J","K","L","M"
    };
    auto ans=sol.findLongestSubarray(array);
    DBGV(ans);

    system("pause");
    return 0;
}
