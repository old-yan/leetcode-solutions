#include "utils.h"

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int>S;
        while(!S.count(n)){
            S.insert(n);
            string s=i2s(n);
            int next=0;
            for(char c:s)next+=(c-'0')*(c-'0');
            n=next;
        }
        return S.count(1);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=19;
    auto ans=sol.isHappy(n);
    DBG(ans);

    system("pause");
    return 0;
}
