#include "utils.h"

class Solution {
public:
    //模拟
    int finalValueAfterOperations(vector<string>& operations) {
        int value=0;
        for(auto &s:operations){
            if(s=="++X" or s=="X++")value++;
            else value--;
        }
        return value;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;
    
    vector<string>operations{"X++","++X","--X","X--"};
    auto ans=sol.finalValueAfterOperations(operations);
    DBG(ans);

    system("pause");
    return 0;
}