#include "utils.h"

class Solution {
public:
    string customSortString(string S, string T) {
        int num[26]={0};
        for(char c:T)num[c-'a']++;
        string ans;
        for(char c:S){
            while(num[c-'a']--)ans+=c;
        }
        for(char c:T){
            if(num[c]>0)ans+=c;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string S="cba";
    string T="abcd";
    auto ans=sol.customSortString(S,T);
    DBG(ans);

    system("pause");
    return 0;
}
