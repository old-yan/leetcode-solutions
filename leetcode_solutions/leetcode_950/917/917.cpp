#include "utils.h"

class Solution {
public:
    string reverseOnlyLetters(string S) {
        int i=0,j=S.size()-1;
        while(true){
            while(S[i]&&!isalpha(S[i]))i++;
            while(j>=0&&!isalpha(S[j]))j--;
            if(i>=j)break;
            swap(S[i++],S[j--]);
        }
        return S;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string S="a-bC-dEf-ghIj";
    auto ans=sol.reverseOnlyLetters(S);
    DBG(ans);

    system("pause");
    return 0;
}
