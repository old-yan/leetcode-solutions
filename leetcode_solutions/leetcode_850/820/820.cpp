#include "Trie.h"
#include "utils.h"

class mytrie:public StaticTrie{
public:
    mytrie():StaticTrie(){}
    template<class iterator>
    bool insert(iterator begin,iterator end,int signal=0){
        int cur=0;
        bool flag;
        for(auto it=begin;it<end;++it){
            data[cur][27]=1;
            if(!data[cur][*it-'a'])Malloc(data[cur][*it-'a']);
            cur=data[cur][*it-'a'];
        }
        flag=data[cur][27];
        data[cur][27]=1;
        data[cur][26]=signal;
        return flag;
    }
};

mytrie T;
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        T.clear();
        sort(ALL(words),[](string&x,string&y){return x.size()>y.size();});
        int ans=0;
        for(auto&word:words){
            if(!T.insert(ALLR(word))){
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
