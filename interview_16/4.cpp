#include "utils.h"

class Solution {
public:
    string tictactoe(vector<string>& board) {
        int m=board.size(),n=board[0].size();
        int all=0;
        REP(i,m){
            int X=0,O=0;
            for(char c:board[i]){
                X+=c=='X';
                O+=c=='O';
                all+=c!=' ';
            }
            if(X==n)return "X";
            if(O==n)return "O";
        }
        REP(j,n){
            int X=0,O=0;
            REP(i,m){
                char c=board[i][j];
                X+=c=='X';
                O+=c=='O';
            }
            if(X==m)return "X";
            if(O==m)return "O";
        }
        {
            int X=0,O=0;
            REP(i,m){
                char c=board[i][i];
                X+=c=='X';
                O+=c=='O';
            }
            if(X==m)return "X";
            if(O==m)return "O";
        }
        {
            int X=0,O=0;
            REP(i,m){
                char c=board[i][n-1-i];
                X+=c=='X';
                O+=c=='O';
            }
            if(X==m)return "X";
            if(O==m)return "O";
        }
        return all==m*n?"Draw":"Pending";
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<string>board{
        "O X"," XO","X O"
    };
    auto ans=sol.tictactoe(board);
    DBG(ans);

    system("pause");
    return 0;
}
