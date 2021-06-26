#include "utils.h"

class Solution {
public:
    string reorderSpaces(string text) {
        int space=accumulate(ALL(text),0,[](int x,char c){return x+(c==' ');});
        vector<string>v;
        for(int i=0,j;i<text.size();){
            if(text[i]==' ')i++;
            else{
                for(j=i+1;text[j]&&text[j]!=' ';j++);
                v.pb(text.substr(i,j-i));
                i=j;
            }
        }
        string ans=v[0];
        if(v.size()==1)return ans+string(space,' ');
        int a=space/(v.size()-1);
        FOR(i,1,v.size()){
            ans+=string(a,' ')+v[i];
        }
        return ans+string(space-a*(v.size()-1),' ');
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string text="  this   is  a sentence ";
    auto ans=sol.reorderSpaces(text);
    DBG(ans);

    system("pause");
    return 0;
}
