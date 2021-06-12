#include "utils.h"

class Solution {
public:
    string replaceSpaces(string S, int length) {
        int space=0;
        REP(i,length)space+=S[i]==' ';
        int cursor=length+space*2-1;
        REPR(i,length-1){
            if(S[i]==' '){
                S[cursor--]='0';
                S[cursor--]='2';
                S[cursor--]='%';
            }
            else S[cursor--]=S[i];
        }
        while(S.back()==' ')S.pop_back();
        return S;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string S="Mr John Smith    ";
    int length=13;
    auto ans=sol.replaceSpaces(S,length);
    DBG(ans);

    system("pause");
    return 0;
}
