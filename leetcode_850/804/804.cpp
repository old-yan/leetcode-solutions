#include "Trie.h"
#include "utils.h"

string s[26]={"ab","baaa","baba","baa","a","aaba","bba","aaaa","aa","abbb","bab","abaa","bb","ba","bbb","abba","bbab","aba","aaa","b","aab","aaab","abb","baab","babb","bbaa"};

StaticTrie T;
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        T.clear();
        for(auto&word:words){
            string t;
            for(char c:word){
                t+=s[c-'a'];
            }            
            T.insert(t);
        }
        return T[0][27];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<string>words{"gin", "zen", "gig", "msg"};
    auto ans=sol.uniqueMorseRepresentations(words);
    DBG(ans);

    system("pause");
    return 0;
}
