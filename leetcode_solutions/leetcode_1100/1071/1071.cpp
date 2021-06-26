#include "utils.h"

class Solution {
    bool check(string&s,string&p){
        for(int i=0;i<s.size();i++){
            if(s[i]!=p[i%p.size()])return false;
        }
        return true;
    }
public:
    string gcdOfStrings(string str1, string str2) {
        for(int l=min(str1.size(),str2.size());l;l--){
            if(str1.size()%l||str2.size()%l)continue;
            string p=str1.substr(0,l);
            if(check(str1,p)&&check(str2,p))return p;
        }
        return "";
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string str1="ABCABC";
    string str2="ABC";
    auto ans=sol.gcdOfStrings(str1,str2);
    DBG(ans);

    system("pause");
    return 0;
}
