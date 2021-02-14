#include "utils.h"

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string s;
        while(s.size()<b.size())s+=a;
        if(int(s.find(b))>=0)return s.size()/a.size();
        if(int((s+a).find(b))>=0)return s.size()/a.size()+1;
        return -1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string a="abcd";
    string b="cdabcdab";
    auto ans=sol.repeatedStringMatch(a,b);
    DBG(ans);

    system("pause");
    return 0;
}
