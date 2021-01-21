#include "utils.h"

class Solution {
    vector<vector<char>>board;
    vvi around;
    int m,n;
    int getAround(int i,int j){
        int count=0;
        for(int ii=i-1;ii<=i+1;ii++){
            for(int jj=j-1;jj<=j+1;jj++){
                if(ii>=0&&ii<m&&jj>=0&&jj<n&&!(i==ii&&j==jj)&&(board[ii][jj]=='M'||board[ii][jj]=='X')){
                    count++;
                }
            }
        }
        return count;
    }
    void dfs(int i,int j){
        if(board[i][j]=='M'){
            board[i][j]='X';
            return;
        }
        else{
            if(around[i][j]==0){
                board[i][j]='B';
                for(int ii=i-1;ii<=i+1;ii++){
                    for(int jj=j-1;jj<=j+1;jj++){
                        if(ii>=0&&ii<m&&jj>=0&&jj<n&&(board[ii][jj]=='M'||board[ii][jj]=='E')){
                            dfs(ii,jj);
                        }
                    }
                }
            }
            else{
                board[i][j]='0'+around[i][j];
            }
        }
    }
public:
    vector<vector<char>> updateBoard(vector<vector<char>>&_board, vector<int>& click) {
        board=_board;
        m=board.size();
        n=board[0].size();
        around.resize(m,vi(n));
        REP(i,m){
            REP(j,n){
                around[i][j]=getAround(i,j);
            }
        }
        dfs(click[0],click[1]);
        return board;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<vector<char>>board{
        {'E', 'E', 'E', 'E', 'E'},
        {'E', 'E', 'M', 'E', 'E'},
        {'E', 'E', 'E', 'E', 'E'},
        {'E', 'E', 'E', 'E', 'E'}
    };
    vi click{3,0};
    auto ans=sol.updateBoard(board,click);
    DBGVV(ans);

    system("pause");
    return 0;
}
