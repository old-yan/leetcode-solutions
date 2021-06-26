#include "utils.h"

class Solution {
public:
    int numberOfSteps(int num) {
        int ans=0;
        while(num){
            if(num%2)num--;
            else num/=2;
            ans++;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int num=14;
    auto ans=sol.numberOfSteps(num);
    DBG(ans);

    system("pause");
    return 0;
}
