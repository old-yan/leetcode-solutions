#include "utils.h"

class Solution {
public:
    //两种变法，一种是把奇数位变'1'，偶数位变'0'，第二种是反之。两种的变化次数和为s.size()
    int minOperations(string s) {
        int cnt=0;
        for(int i=0;i<s.size();i++)if(s[i]%2!=i%2)cnt++;
        return min(cnt,int(s.size()-cnt));
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="1111";
    auto ans=sol.minOperations(s);
    DBG(ans);

    system("pause");
    return 0;
}
