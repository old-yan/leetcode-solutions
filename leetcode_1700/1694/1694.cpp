#include "utils.h"

class Solution {
public:
    string reformatNumber(string number) {
        string s;
        for(char c:number)if(c!=' '&&c!='-')s+=c;
        int cursor=0;
        string ans;
        while(s.size()-cursor>4){
            ans+=s.substr(cursor,3)+"-";
            cursor+=3;
        }
        if(s.size()-cursor==4){
            ans+=s.substr(cursor,2)+"-"+s.substr(cursor+2,2);
        }
        else{
            ans+=s.substr(cursor);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string number="1-23-45 6";
    auto ans=sol.reformatNumber(number);
    DBG(ans);

    system("pause");
    return 0;
}
