#include "utils.h"

class Solution {
public:
    int numDifferentIntegers(string word) {
        unordered_set<string>S;
        for(int i=0,j;i<word.size();i=j){
            while(word[i]&&!isdigit(word[i]))i++;
            if(!word[i])break;
            for(j=i+1;isdigit(word[j]);j++);
            string s=word.substr(i,j-i);
            while(s[0]=='0'&&s.size()>1)s=s.substr(1);
            S.insert(s);
        }
        return S.size();
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string word="a123bc34d8ef34";
    auto ans=sol.numDifferentIntegers(word);
    DBG(ans);

    system("pause");
    return 0;
}
