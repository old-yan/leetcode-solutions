#include "utils.h"

class Solution {
public:
    string reverseWords(string s) {
        vector<string>v;
        for(int i=0,j;i<s.size();i=j){
            while(s[i]==' ')i++;
            if(!s[i])break;
            for(j=i+1;s[j]&&s[j]!=' ';j++);
            v.pb(s.substr(i,j-i));
        }
        string ans;
        REPR(i,v.size()-1){
            if(!i)ans+=v[i];
            else ans+=v[i]+" ";
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="the sky is blue";
    auto ans=sol.reverseWords(s);
    DBG(ans);

    system("pause");
    return 0;
}
