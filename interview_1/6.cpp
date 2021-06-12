#include "utils.h"

class Solution {
public:
    string compressString(string S) {
        string ans;
        for(int i=0,j;i<S.size();i=j){
            for(j=i+1;S[j]==S[i];j++);
            ans+=S[i]+i2s(j-i);
        }
        if(ans.size()>=S.size())return S;
        else return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string S="aabcccccaaa";
    auto ans=sol.compressString(S);
    DBG(ans);

    system("pause");
    return 0;
}
