#include "utils.h"

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans;
        int a=0,rest=0;
        for(char c:s)rest+=c==')';
        for(char c:s){
            if(isalpha(c))ans+=c;
            else if(c=='('){
                if(rest>a){
                    ans+=c;
                    a++;
                }
            }
            else{
                rest--;
                if(a){
                    ans+=c;
                    a--;
                }
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="lee(t(c)o)de)";
    auto ans=sol.minRemoveToMakeValid(s);
    DBG(ans);

    system("pause");
    return 0;
}
