#include "utils.h"

class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int Xcount=0,Ocount=0;
        REP(i,3){
            REP(j,3){
                if(board[i][j]=='X')Xcount++;
                else if(board[i][j]=='O')Ocount++;
            }
        }
        if(Xcount!=Ocount&&Xcount!=Ocount+1)return false;
        char winner=Xcount==Ocount?'O':'X';
        vi lines;
        REP(i,3){
            if(board[i][0]==board[i][1]&&board[i][1]==board[i][2]){
                if(board[i][0]==' ')continue;
                if(board[i][0]!=winner)return false;
                lines.pb((1<<(i*3))+(1<<(i*3+1))+(1<<(i*3+2)));
            }
        }
        cout<<lines.size();
        REP(j,3){
            if(board[0][j]==board[1][j]&&board[1][j]==board[2][j]){
                if(board[0][j]==' ')continue;
                if(board[0][j]!=winner)return false;
                lines.pb((1<<j)+(1<<(j+3))+(1<<(j+6)));
            }
        }
        if(board[0][0]==board[1][1]&&board[1][1]==board[2][2]){
            if(board[0][0]!=' '){
                if(board[0][0]!=winner)return false;
                lines.pb((1<<0)+(1<<4)+(1<<8));
            }
        }
        if(board[0][2]==board[1][1]&&board[1][1]==board[2][0]){
            if(board[0][2]!=' '){
                if(board[0][2]!=winner)return false;
                lines.pb((1<<2)+(1<<4)+(1<<6));
            }
        }
        if(lines.size()>1){
            int join=lines[0]&lines[1];
            if(__builtin_popcount(join)!=1)return false;
            REP(i,lines.size())REP(j,i)if((lines[i]&lines[j])!=join)return false;
        }
        return true;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<string>board{"XOX", " X ", "   "};
    auto ans=sol.validTicTacToe(board);
    DBG(ans);

    system("pause");
    return 0;
}
