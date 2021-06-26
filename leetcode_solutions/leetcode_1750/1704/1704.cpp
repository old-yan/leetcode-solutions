#include "utils.h"

class Solution {
    bool isVow[128]={0};
    void init(){
        string s="aeiouAEIOU";
        for(char c:s)isVow[c]=true;
    }
public:
    bool halvesAreAlike(string s) {
        init();
        int a=0,b=0;
        REP(i,s.size()/2)if(isVow[s[i]])a++;
        FOR(i,s.size()/2,s.size())if(isVow[s[i]])b++;
        return a==b;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="book";
    auto ans=sol.halvesAreAlike(s);
    DBG(ans);

    system("pause");
    return 0;
}
