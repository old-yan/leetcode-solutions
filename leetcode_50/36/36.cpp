#include "utils.h"

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        REP(i,9){
            int count[128]={0};
            REP(j,9){
                char c=board[i][j];
                if(c!='.'&&count[c]++)return false;
            }
        }
        REP(j,9){
            int count[128]={0};
            REP(i,9){
                char c=board[i][j];
                if(c!='.'&&count[c]++)return false;
            }
        }
        REP(i,9){
            int count[128]={0};
            REP(j,9){
                char c=board[i/3*3+j/3][i%3*3+j%3];
                if(c!='.'&&count[c]++)return false;
            }
        }
        return true;
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
    auto ans=sol.isValidSudoku(board);
    DBG(ans);

    system("pause");
    return 0;
}
