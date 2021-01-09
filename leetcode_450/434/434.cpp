#include "utils.h"

class Solution {
public:
    int countSegments(string s) {
        int prelen=0;
        int ans=0;
        for(char c:s){
            if(c==' '){
                if(prelen){
                    ans++;
                    prelen=0;
                }
            }
            else prelen++;
        }
        if(prelen)ans++;
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="Hello, my name is John";
    auto ans=sol.countSegments(s);
    DBG(ans);

    system("pause");
    return 0;
}
