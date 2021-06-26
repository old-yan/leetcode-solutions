#include "utils.h"

class Solution {
public:
    string reformat(string s) {
        string digits,alphas;
        for(char c:s){
            if(isdigit(c))digits+=c;
            else alphas+=c;
        }
        if(digits.size()>alphas.size()+1||alphas.size()>digits.size()+1)return "";
        if(digits.size()>alphas.size()){
            string ans;
            while(digits.size()){
                ans+=digits.back();
                digits.pop_back();
                if(alphas.size()){
                    ans+=alphas.back();
                    alphas.pop_back();
                }
            }
            return ans;
        }
        else{
            string ans;
            while(alphas.size()){
                ans+=alphas.back();
                alphas.pop_back();
                if(digits.size()){
                    ans+=digits.back();
                    digits.pop_back();
                }
            }
            return ans;
        }
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="a0b1c2";
    auto ans=sol.reformat(s);
    DBG(ans);

    system("pause");
    return 0;
}
