#include "utils.h"

class Solution {
    int row[9][10]={0};
    int col[9][10]={0};
    int square[9][10]={0};
    bool dfs(int i,int j,vector<vector<char>>&board){
        if(i==9)return true;
        char init=board[i][j];
        if(init!='.'){
            if(++j==9){
                i++,j=0;
            }
            return dfs(i,j,board);
        }
        else{
            for(char c='1';c<='9';c++){
                if(!row[i][c-'0']&&!col[j][c-'0']&&!square[i/3+j/3*3][c-'0']){
                    board[i][j]=c;
                    row[i][c-'0']=1;
                    col[j][c-'0']=1;
                    square[i/3+j/3*3][c-'0']=1;
                    int ii=i,jj=j+1;
                    if(jj==9){
                        ii++,jj=0;
                    }
                    if(dfs(ii,jj,board))return true;
                    row[i][c-'0']=0;
                    col[j][c-'0']=0;
                    square[i/3+j/3*3][c-'0']=0;
                }
            }
            board[i][j]=init;
            return false;
        }
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        REP(i,9){
            REP(j,9){
                char c=board[i][j];
                if(c!='.'){
                    row[i][c-'0']=1;
                    col[j][c-'0']=1;
                    square[i/3+j/3*3][c-'0']=1;
                }
            }
        }
        dfs(0,0,board);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<vector<char>>board={
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    sol.solveSudoku(board);
    DBGVV(board);

    system("pause");
    return 0;
}
