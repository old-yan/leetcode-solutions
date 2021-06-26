#include "utils.h"

class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        int ans=0;
        for(auto&word:words){
            int idx=-1;
            for(char c:word){
                idx=S.find(c,idx+1);
                if(idx<0)break;
            }
            if(idx>=0)ans++;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string S="abcde";
    vector<string>words{
        "a","bb","acd","ace"
    };
    auto ans=sol.numMatchingSubseq(S,words);
    DBG(ans);

    system("pause");
    return 0;
}
