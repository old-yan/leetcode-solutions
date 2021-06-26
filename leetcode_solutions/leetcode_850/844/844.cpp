#include "utils.h"

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int i=S.size(),j=T.size();
        while(i>=0&&j>=0){
            if(S[i--]!=T[j--])return false;
            for(int signal=0;i>=0&&(S[i]=='#'||signal);i--){
                if(S[i]=='#')signal++;
                else signal--;
            }
            for(int signal=0;j>=0&&(T[j]=='#'||signal);j--){
                if(T[j]=='#')signal++;
                else signal--;
            }
        }
        return i<0&&j<0;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string S="ab#c";
    string T="ad#c";
    auto ans=sol.backspaceCompare(S,T);
    DBG(ans);

    system("pause");
    return 0;
}
