#include "utils.h"

class Solution {
public:
    bool checkOnesSegment(string s) {
        int cnt=0;
        for(int i=0,j;i<s.size();i=j){
            for(j=i+1;s[j]==s[i];j++);
            if(s[i]=='1')cnt++;
        }
        return cnt<=1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="1001";
    auto ans=sol.checkOnesSegment(s);
    DBG(ans);

    system("pause");
    return 0;
}
