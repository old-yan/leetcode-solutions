#include "utils.h"

class Solution {
    int m,n;
    vector<vector<char>>board;
    string word;
    bool visited[200][200]={0};
    bool dfs(int i,int j,int idx){
        if(idx==word.size()-1)return true;
        visited[i][j]=true;
        REP(k,4){
            int ii=i+di[k],jj=j+dj[k];
            if(ii>=0&&ii<m&&jj>=0&&jj<n&&!visited[ii][jj]&&board[ii][jj]==word[idx+1]){
                if(dfs(ii,jj,idx+1))return true;
            }
        }
        visited[i][j]=false;
        return false;
    }
public:
    bool exist(vector<vector<char>>&_board, string _word) {
        board=_board;
        m=board.size();
        n=board[0].size();
        word=_word;
        REP(i,m){
            REP(j,n){
                if(board[i][j]==word[0]&&dfs(i,j,0))return true;
            }
        }
        return false;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<vector<char>>board{
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    string word="ABCB";
    auto ans=sol.exist(board,word);
    DBG(ans);

    system("pause");
    return 0;
}
