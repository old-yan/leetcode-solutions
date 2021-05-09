#include "utils.h"

class Solution {
public:
    string thousandSeparator(int n) {
        string s=i2s(n);
        int cur=3-s.size()%3;
        string ans;
        for(char c:s){
            ans+=c;
            if(++cur%3==0)ans+='.';
        }
        return ans.substr(0,ans.size()-1);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=987;
    auto ans=sol.thousandSeparator(n);
    DBG(ans);

    system("pause");
    return 0;
}
