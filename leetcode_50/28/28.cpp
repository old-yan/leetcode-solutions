#include "utils.h"

class Solution {
public:
    int strStr(string haystack, string needle) {
        //return haystack.find(needle);
        vi next=getnext(needle);
        for(int i=0,j=0;;){
            if(j==needle.size())return i-j;
            if(i==haystack.size())break;
            if(j<0||haystack[i]==needle[j]){
                i++,j++;
            }
            else{
                j=next[j];
            }
        }
        return -1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string haystack="hello";
    string needle="ll";
    auto ans=sol.strStr(haystack,needle);
    DBG(ans);

    system("pause");
    return 0;
}
