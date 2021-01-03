#include "utils.h"

class Solution {
public:
    string reverseVowels(string s) {
        int i=0,j=s.size()-1;
        set<char>S{'a','e','i','o','u','A','E','I','O','U'};
        while(i<j){
            while(i<=j&&!S.count(s[i]))i++;
            if(i>j)break;
            while(j>=i&&!S.count(s[j]))j--;
            swap(s[i],s[j]);
        }
        return s;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="hello";
    auto ans=sol.reverseVowels(s);
    DBG(ans);

    system("pause");
    return 0;
}
