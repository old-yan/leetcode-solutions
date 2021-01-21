#include "utils.h"

class Solution {
public:
    int nextGreaterElement(int n) {
        string s=i2s(n);
        int i;
        for(i=int(s.size())-2;i>=0&&s[i]>=s[i+1];i--);
        if(i<0)return -1;
        int j;
        for(j=int(s.size())-1;s[j]<=s[i];j--);
        swap(s[i],s[j]);
        reverse(s.begin()+i+1,s.end());
        return s2i(s);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=12;
    auto ans=sol.nextGreaterElement(n);
    DBG(ans);

    system("pause");
    return 0;
}
