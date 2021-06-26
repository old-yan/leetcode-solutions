#include "Trie.h"
#include "utils.h"

StaticTrie T;
class Solution {
    bool dfs(int idx,string&s){
        if(idx==s.size())return true;
        else{
            int cur=0;
            FOR(j,idx,s.size()){
                cur=T[cur][s[j]-'a'];
                if(!cur)break;
                if(T[cur][26]>=0&&dfs(j+1,s))return true;
            }
            return false;
        }
    }
public:
    string longestWord(vector<string>& words) {
        T.clear();
        sort(ALL(words),[](auto&x,auto&y){return x.size()<y.size();});
        string ans;
        for(string&s:words){
            if(dfs(0,s)){
                if(s.size()>ans.size())ans=s;
                else if(s.size()==ans.size())chmin(ans,s);
            }
            T.insert(s);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<string>words{
        "cat","banana","dog","nana","walk","walker","dogwalker"
    };
    auto ans=sol.longestWord(words);
    DBG(ans);

    system("pause");
    return 0;
}
