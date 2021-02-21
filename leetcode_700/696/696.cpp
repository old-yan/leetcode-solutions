#include "utils.h"

class Solution {
public:
    int countBinarySubstrings(string s) {
        vi next=next_different(s);
        vi prev=prev_different(s);
        int ans=0;
        for(int i=0;next[i]<s.size();i=next[i]){
            ans+=min(next[i]-i,next[next[i]]-next[i]);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="00110011";
    auto ans=sol.countBinarySubstrings(s);
    DBG(ans);

    system("pause");
    return 0;
}
