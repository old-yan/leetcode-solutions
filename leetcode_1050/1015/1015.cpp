#include "utils.h"

class Solution {
public:
    int smallestRepunitDivByK(int K) {
        if(K==1)return 1;
        int cur=1,ans=1;
        unordered_set<int>S({1});
        while(cur){
            cur=(cur*10+1)%K;
            if(!S.insert(cur).second)return -1;
            ans++;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int K=1234;
    auto ans=sol.smallestRepunitDivByK(K);
    DBG(ans);

    system("pause");
    return 0;
}
