#include "utils.h"

class Solution {
public:
    int numSplits(string s) {
        int leftcnt[26]={0},rightcnt[26]={0},left=0,right=0;
        for(char c:s){
            if(!rightcnt[c-'a']++)right++;
        }
        int ans=0;
        for(char c:s){
            if(!--rightcnt[c-'a'])right--;
            if(!leftcnt[c-'a']++)left++;
            ans+=left==right;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="aacaba";
    auto ans=sol.numSplits(s);
    DBG(ans);

    system("pause");
    return 0;
}
