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


class Solution {
    vector<vector<char>>board;
    vector<string>words;
    bool used[12][12]={0};
    vector<string>ans;
    int dfs(StaticTrie&T,int&cur,int i,int j){
        int num_of_deleted=0;
        int&next=T[cur][board[i][j]-'a'];
        if(T[next][26]){
            ans.pb(words[T[next][26]-1]);
            T[next][26]=0;
            num_of_deleted=1;
            if(!--T[next][27]){
                T.Free(next);
            };
        }
        used[i][j]=true;
        REP(k,4){
            int ii=i+di[k],jj=j+dj[k];
            if(ii>=0&&ii<board.size()&&jj>=0&&jj<board[0].size()&&!used[ii][jj]&&next&&T[next][board[ii][jj]-'a']){
                num_of_deleted+=dfs(T,next,ii,jj);
            }
        }
        used[i][j]=false;
        if(!(T[cur][27]-=num_of_deleted)){
            T.Free(cur);
        }
        return num_of_deleted;
    }
public:
    vector<string> findWords(vector<vector<char>>&_board, vector<string>&_words) {
        board=_board;
        words=_words;
        StaticTrie T(words.size()*10+1);
        int cur=0;
        REP(i,words.size())T.insert(words[i],i);
        REP(i,board.size()){
            REP(j,board[0].size()){
                dfs(T,cur,i,j);
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
