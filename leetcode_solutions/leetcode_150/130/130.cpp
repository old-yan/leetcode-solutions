#include "utils.h"

class Solution {
    vector<vector<char>>board;
    int m,n;
    void dfs(int i,int j){
        board[i][j]='Q';
        REP(k,4){
            int ii=i+di[k],jj=j+dj[k];
            if(VALID&&board[ii][jj]=='O'){
                dfs(ii,jj);
            }
        }
    }
public:
    void solve(vector<vector<char>>&_board) {
        board=_board;
        m=board.size();
        if(!m)return;
        n=board[0].size();
        REP(i,m){
            REP(j,n){
                if(board[i][j]=='O'&&(i==0||i==m-1||j==0||j==n-1)){
                    dfs(i,j);
                }
            }
        }
        REP(i,m){
            REP(j,n){
                if(board[i][j]=='O'){
                    _board[i][j]='X';
                }
            }
        }
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<vector<char>>board{
        {'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}
    };
    sol.solve(board);
    DBGVV(board);

    system("pause");
    return 0;
}
