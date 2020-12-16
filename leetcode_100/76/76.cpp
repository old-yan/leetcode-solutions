#include "utils.h"

class Solution {
public:
    string minWindow(string s, string t) {
        int count[128]={0},n=0;
        for(char c:t){
            if(!count[c]++){
                n++;
            }
        }
        string ans;
        int anslen=INT_MAX;
        for(int i=0,j=0;i<s.size();i++){
            while(s[j]&&n){
                if(!--count[s[j++]])n--;
            }
            if(!n&&chmin(anslen,j-i))ans=s.substr(i,j-i);
            if(!count[s[i]]++)n++;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="ADOBECODEBANC";
    string t="ABC";
    auto ans=sol.minWindow(s,t);
    DBG(ans);

    system("pause");
    return 0;
}
