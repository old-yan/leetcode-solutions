#include "utils.h"

class Solution {
    int upper[26],lower[26],lonely_upper,lonely_lower;
    void Addupper(char c){
        if(!upper[c-'A']++){
            if(!lower[c-'A'])lonely_upper++;
            else lonely_lower--;
        }
    }
    void Addlower(char c){
        if(!lower[c-'a']++){
            if(!upper[c-'a'])lonely_lower++;
            else lonely_upper--;
        }
    }
public:
    string longestNiceSubstring(string s) {
        string ans;
        for(int i=0;i<s.size();i++){
            memset(upper,0,sizeof(upper));
            memset(lower,0,sizeof(lower));
            lonely_lower=lonely_upper=0;
            for(int j=i;j<s.size();j++){
                if(isupper(s[j]))Addupper(s[j]);
                else Addlower(s[j]);
                if(!lonely_lower&&!lonely_upper&&j-i+1>ans.size()){
                    ans=s.substr(i,j-i+1);
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

    string s="YazaAay";
    auto ans=sol.longestNiceSubstring(s);
    DBG(ans);

    system("pause");
    return 0;
}
