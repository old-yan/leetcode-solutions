#include "Trie.h"
#include "utils.h"

class mytrie:public StaticTrie{
public:
    int maxlen,maxlen_idx;
    mytrie():StaticTrie(),maxlen(0){}
    void traverse(int cur,int len){
        if(cur&&(*this)[cur][26]<0)return;
        REP(i,26){
            if((*this)[cur][i]){
                traverse((*this)[cur][i],len+1);
            }
        }
        if(chmax(maxlen,len))maxlen_idx=(*this)[cur][26];
    }
};

mytrie T;
class Solution {
public:
    string longestWord(vector<string>& words) {
        T.clear();
        T.maxlen=0;
        REP(i,words.size())T.insert(words[i],i);
        T.traverse(0,0);
        return T.maxlen?words[T.maxlen_idx]:"";
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<string>words{
        "w","wo","wor","worl", "world"
    };
    auto ans=sol.longestWord(words);
    DBG(ans);

    system("pause");
    return 0;
}
