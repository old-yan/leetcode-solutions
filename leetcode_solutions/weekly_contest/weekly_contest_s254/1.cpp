#include "utils.h"

class Solution {
public:
    //逐个判断即可
    int numOfStrings(vector<string>& patterns, string word) {
        int ans=0;
        for(string&s:patterns){
            ans+=int(word.find(s))>=0;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<string>patterns{
        "a","abc","bc","d"
    };
    string word="abc";
    auto ans=sol.numOfStrings(patterns,word);
    DBG(ans);

    system("pause");
    return 0;
}
