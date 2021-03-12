#include "Trie.h"
#include "utils.h"

class mytrie:public StaticTrie{
public:
    mytrie():StaticTrie(){}
    bool insert(const string&word) {
        int cur=0;
        bool newd=false;
        for(int i=word.size()-1;i>=0;i--){
            if(!(*this)[cur][word[i]-'a']){
                Malloc((*this)[cur][word[i]-'a']);
                newd=true;
            }
            cur=(*this)[cur][word[i]-'a'];
        }
        return newd;
    }
};

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        mytrie T;
        sort(ALL(words),[](string&x,string&y){return x.size()>y.size();});
        int ans=0;
        for(auto&word:words){
            if(T.insert(word)){
                ans+=word.size()+1;
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<string>words{"time", "me", "bell"};
    auto ans=sol.minimumLengthEncoding(words);
    DBG(ans);

    system("pause");
    return 0;
}
