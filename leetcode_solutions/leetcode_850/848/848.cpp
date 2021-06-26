#include "utils.h"

class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        ll cnt=0;
        REPR(i,S.size()-1){
            cnt+=shifts[i];
            S[i]='a'+(cnt+(S[i]-'a'))%26;
        }
        return S;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string S="abc";
    vi shifts{3,5,9};
    auto ans=sol.shiftingLetters(S,shifts);
    DBG(ans);

    system("pause");
    return 0;
}
