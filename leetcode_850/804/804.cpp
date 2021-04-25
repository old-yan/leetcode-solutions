#include "Trie.h"
#include "utils.h"

class mytrie:public StaticTrie{
public:
    int count;
    mytrie():StaticTrie(),count(0){}
    void clear(){
        StaticTrie::clear();
        count=0;
    }
    void insert(const string&word){
        int cur=0;
        for(char c:word){
            if(!data[cur][c-'a'])Malloc(data[cur][c-'a']);
            cur=data[cur][c-'a'];
        }
        if(data[cur][26]<0)count++;
        data[cur][26]=0;
    }
};

string s[26]={"ab","baaa","baba","baa","a","aaba","bba","aaaa","aa","abbb","bab","abaa","bb","ba","bbb","abba","bbab","aba","aaa","b","aab","aaab","abb","baab","babb","bbaa"};
mytrie T;
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
        return T.count;
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
