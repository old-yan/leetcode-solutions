#include "utils.h"

class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int pre=0;
        int ans=0;
        for(int a:target){
            if(a>pre)ans+=a-pre;
            pre=a;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi target{1,2,3,2,1};
    auto ans=sol.minNumberOperations(target);
    DBG(ans);

    system("pause");
    return 0;
}
