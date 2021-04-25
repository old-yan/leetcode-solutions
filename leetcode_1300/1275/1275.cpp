#include "utils.h"

class Solution {
    char a[3][3]={0};
    bool checkOver(){
        REP(i,3){
            int x=0,o=0;
            REP(j,3){
                x+=a[i][j]=='X';
                o+=a[i][j]=='O';
            }
            if(x==3||o==3)return true;
        }
        REP(j,3){
            int x=0,o=0;
            REP(i,3){
                x+=a[i][j]=='X';
                o+=a[i][j]=='O';
            }
            if(x==3||o==3)return true;
        }
        {
            int x=0,o=0;
            REP(i,3){
                x+=a[i][i]=='X';
                o+=a[i][i]=='O';
            }
            if(x==3||o==3)return true;
        }
        {
            int x=0,o=0;
            REP(i,3){
                x+=a[i][2-i]=='X';
                o+=a[i][2-i]=='O';
            }
            if(x==3||o==3)return true;
        }
    }
public:
    string tictactoe(vector<vector<int>>& moves) {
        REP(i,moves.size()){
            int j=moves[i][0],k=moves[i][1];
            a[j][k]=i%2?'O':'X';
            if(checkOver())return i%2?"B":"A";
        }
        return moves.size()==9?"Draw":"Pending";
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi moves=makevvi("[[0,0],[2,0],[1,1],[2,1],[2,2]]");
    auto ans=sol.tictactoe(moves);
    DBG(ans);

    system("pause");
    return 0;
}
