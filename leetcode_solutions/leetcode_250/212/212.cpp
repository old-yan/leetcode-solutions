#include "Trie.h"
#include "utils.h"

// /*基于动态Trie树和静态Trie树，都可以解决本问题*/
// class Solution {
//     vector<vector<char>>board;
//     vector<string>words;
//     bool used[12][12]={0};
//     DynamicTrie*T;
//     vector<string>ans;
//     int dfs(DynamicTrie*&t,int i,int j){
//         int num_of_deleted=0;
//         auto&next=t->child[board[i][j]-'a'];
//         if(next->signal>=0){
//             ans.pb(words[next->signal]);
//             next->signal=-1;
//             num_of_deleted=1;
//             if(!--next->num_of_son){
//                 delete next;
//                 next=nullptr;
//             };
//         }
//         used[i][j]=true;
//         REP(k,4){
//             int ii=i+di[k],jj=j+dj[k];
//             if(ii>=0&&ii<board.size()&&jj>=0&&jj<board[0].size()&&!used[ii][jj]&&next&&next->child[board[ii][jj]-'a']){
//                 num_of_deleted+=dfs(next,ii,jj);
//             }
//         }
//         used[i][j]=false;
//         if(!(t->num_of_son-=num_of_deleted)){
//             delete t;
//             t=nullptr;
//         }
//         return num_of_deleted;
//     }
// public:
//     vector<string> findWords(vector<vector<char>>&_board, vector<string>&_words) {
//         board=_board;
//         words=_words;
//         T=new DynamicTrie;
//         REP(i,words.size())T->insert(words[i],0,i);
//         REP(i,board.size()){
//             REP(j,board[0].size()){
//                 if(T&&T->child[board[i][j]-'a']){
//                     dfs(T,i,j);
//                 }
//             }
//         }
//         return ans;
//     }
// };


class mytrie:public StaticTrie{
public:
    mytrie():StaticTrie(){}
    void insert(const string&word,int signal){
        int cur=0;
        for(char c:word){
            data[cur][27]++;
            if(!data[cur][c-'a'])Malloc(data[cur][c-'a']);
            cur=data[cur][c-'a'];
        }
        data[cur][26]=signal;
        data[cur][27]++;
    }
};

mytrie T;
class Solution {
    vector<vector<char>>board;
    vector<string>words;
    int m,n;
    bool used[12][12]={0};
    vector<string>ans;
    int dfs(int&cur,int i,int j){
        int num_of_deleted=0;
        if(T[cur][26]>=0){
            ans.pb(words[T[cur][26]]);
            T[cur][26]=-1;
            num_of_deleted++;
        }
        used[i][j]=true;
        REP(k,4){
            int ii=i+di[k],jj=j+dj[k];
            if(VALID&&!used[ii][jj]&&T[cur][board[ii][jj]-'a']){
                num_of_deleted+=dfs(T[cur][board[ii][jj]-'a'],ii,jj);
            }
        }
        used[i][j]=false;
        if(!(T[cur][27]-=num_of_deleted))cur=0;
        return num_of_deleted;
    }
public:
    vector<string> findWords(vector<vector<char>>&_board, vector<string>&_words) {
        board=_board;
        words=_words;
        m=board.size(),n=board[0].size();
        T.clear();
        REP(i,words.size())T.insert(words[i],i);
        REP(i,m)REP(j,n){
            if(T[0][board[i][j]-'a']){
                if(!(T[0][27]-=dfs(T[0][board[i][j]-'a'],i,j)))break;
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<vector<char>>board{
        {'o','a','a','n'},
        {'e','t','a','e'},
        {'i','h','k','r'},
        {'i','f','l','v'}
    };
    vector<string>words{"oath","pea","eat","rain"};
    auto ans=sol.findWords(board,words);
    DBGV(ans);

    system("pause");
    return 0;
}
