#include "utils.h"

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i,j,n=s.size(),ans=0;
        unordered_set<int>S;
        for(i=j=0;i<n;i++){
            while(j<n&&!S.count(s[j])){
                S.insert(s[j++]);
            }
            chmax(ans,j-i);
            S.erase(s[i]);
        }
        return ans;
    }
};

int main(){
    Solution sol;

    string s="abcabcbb";
    auto ans=sol.lengthOfLongestSubstring(s);
    DBG(ans);

    system("pause");
}