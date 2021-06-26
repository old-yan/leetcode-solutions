#include "utils.h"

class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string ans;
        while(a&&b){
            if(b>a*2)ans+='b';
            else if(a>b*2)ans+='a';
            else{
                if(ans.size()&&ans.back()=='a')ans+='b';
                else ans+='a';
            }
            ans.back()=='a'?a--:b--;
        }
        while(a--)ans+='a';
        while(b--)ans+='b';
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int a=1;
    int b=2;
    auto ans=sol.strWithout3a3b(a,b);
    DBG(ans);

    system("pause");
    return 0;
}
