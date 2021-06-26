#include "utils.h"

class Solution {
public:
    int lengthOfLastWord(string s) {
        int blank=1,prelen=0;
        for(char c:s){
            if(c==' ')blank=1;
            else{
                if(blank){
                    prelen=0;
                    blank=0;
                }
                prelen++;
            }
        }
        return prelen;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="Hello World";
    auto ans=sol.lengthOfLastWord(s);
    DBG(ans);

    system("pause");
    return 0;
}
