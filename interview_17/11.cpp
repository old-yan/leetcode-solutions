#include "utils.h"

class Solution {
public:
    int findClosest(vector<string>& words, string word1, string word2) {
        int a=-1000000,b=-1000000,ans=INT_MAX;
        REP(i,words.size()){
            if(words[i]==word1){
                a=i;
                chmin(ans,a-b);
            }
            else if(words[i]==word2){
                b=i;
                chmin(ans,b-a);
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<string>words{
        "I","am","a","student","from","a","university","in","a","city"
    };
    string word1="a";
    string word2="student";
    auto ans=sol.findClosest(words,word1,word2);
    DBG(ans);

    system("pause");
    return 0;
}
