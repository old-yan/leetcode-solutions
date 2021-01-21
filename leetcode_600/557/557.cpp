#include "utils.h"

class Solution {
public:
    string reverseWords(string s) {
        for(int i=0,j;i<s.size();){
            if(s[i]!=' '){
                for(j=i+1;s[j]&&s[j]!=' ';j++);
                reverse(&s[i],&s[j]);
                i=j;
            }
            else i++;
        }
        return s;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="Let's take LeetCode contest";
    auto ans=sol.reverseWords(s);
    DBG(ans);

    system("pause");
    return 0;
}
