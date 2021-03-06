#include "utils.h"

class Solution {
public:
    int expressiveWords(string S, vector<string>& words) {
        auto next=next_different(S);
        int ans=0;
        for(auto&word:words){
            bool b=true;
            int cursor=0;
            for(int i=0,j;i<word.size();i=j,cursor=next[cursor]){
                if(word[i]!=S[cursor]){
                    b=false;
                    break;
                }
                j=word.find_first_not_of(word[i],i);
                if(j<0)j=word.size();
                if(next[cursor]-cursor<j-i||(next[cursor]==cursor+2&&j==i+1)){
                    b=false;
                    break;
                }
            }
            if(cursor==S.size()&&b)ans++;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string S="heeellooo";
    vector<string>words{"hello", "hi", "helo"};
    auto ans=sol.expressiveWords(s,words);
    DBG(ans);

    system("pause");
    return 0;
}
