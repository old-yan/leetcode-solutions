#include "utils.h"

class Solution {
public:
    string makeGood(string s) {
        string ans;
        for(char c:ans){
            if(ans.size()){
                if(islower(ans.back())){
                    if(c==ans.back()-'a'+'A')ans.pop_back();
                    else ans+=c;
                }
                else{
                    if(c==ans.back()-'A'+'a')ans.pop_back();
                    else ans+=c;
                }
            }
            else ans+=c;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="leEeetcode";
    auto ans=sol.makeGood(s);
    DBG(ans);

    system("pause");
    return 0;
}
