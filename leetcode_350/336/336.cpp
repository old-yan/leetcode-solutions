#include "utils.h"

// 动态Trie树和静态Trie树效率基本差不多，一般来说动态最好理解不容易出错
// class Solution {
//     typedef DynamicTrie Trie;
//     vector<string>words;
//     vvi arm;
//     vvi ans;
//     void dfs(Trie*p,int i){
//         if(p->signal>=0){
//             int j=p->signal;
//             int li=words[i].size(),lj=words[j].size();
//             if(lj>li&&arm[j][li+lj+1]==lj-li)ans.pb({j,i});
//         }
//         REP(j,26){
//             if(p->child[j]){
//                 dfs(p->child[j],i);
//             }
//         }
//     }
// public:
//     vector<vector<int>> palindromePairs(vector<string>&_words) {
//         words=_words;
//         Trie T;
//         REP(i,words.size()){
//             T.insert(words[i],i);
//             arm.emplace_back(getarm(words[i]));
//         }
//         REP(i,words.size()){
//             string&word=words[i];
//             auto p=&T;
//             if(p->signal>=0&&p->signal!=i){
//                 if(arm[i][word.size()+1]==word.size())ans.pb({p->signal,int(i)});
//             }
//             FORR(j,int(word.size())-1,0){
//                 p=p->child[word[j]-'a'];
//                 if(!p)break;
//                 if(p->signal>=0&&p->signal!=i){
//                     if(arm[i][j+1]==j)ans.pb({p->signal,int(i)});
//                 }
//             }
//             if(p){
//                 dfs(p,i);
//             }
//         }
//         return ans;
//     }
// };

class Solution {
    typedef StaticTrie Trie;
    vector<string>words;
    Trie T;
    vvi arm;
    vvi ans;
    void dfs(int p,int i){
        if(T[p][26]>0){
            int j=T[p][26]-1;
            int li=words[i].size(),lj=words[j].size();
            if(lj>li&&arm[j][li+lj+1]==lj-li)ans.pb({j,i});
        }
        REP(j,26){
            if(T[p][j]){
                dfs(T[p][j],i);
            }
        }
    }
public:
    vector<vector<int>> palindromePairs(vector<string>&_words) {
        words=_words;
        REP(i,words.size()){
            T.insert(words[i],i);
            arm.emplace_back(getarm(words[i]));
        }
        REP(i,words.size()){
            string&word=words[i];
            int p=0;
            if(T[p][26]>0&&T[p][26]!=i+1){
                if(arm[i][word.size()+1]==word.size())ans.pb({T[p][26]-1,int(i)});
            }
            FORR(j,int(word.size())-1,0){
                p=T[p][word[j]-'a'];
                if(!p)break;
                if(T[p][26]>0&&T[p][26]!=i+1){
                    if(arm[i][j+1]==j)ans.pb({T[p][26]-1,int(i)});
                }
            }
            if(word.empty())dfs(p,i);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<string>words{"a",""};
    auto ans=sol.palindromePairs(words);
    DBGVV(ans);

    system("pause");
    return 0;
}