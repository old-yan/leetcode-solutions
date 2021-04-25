#include "utils.h"

class Solution {
    struct node{
        ll val;
        int cnt;
        node():val(LLONG_MIN),cnt(0){}
        node(ll _val,int _cnt):val(_val),cnt(_cnt){}
        node operator+(const node&other)const{
            if(val==other.val)return node(val,(cnt+other.cnt)%MOD);
            else return val>other.val?*this:other;
        }
        node operator+(const ll inc)const{
            return node(val+inc,cnt);
        }
    };
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int m=board.size(),n=m;
        node dp[m+1][n+1];
        dp[0][0]=node(0,1);
        REP(i,m)REP(j,n)if(board[i][j]!='X'){
            ll inc=isdigit(board[i][j])?board[i][j]-'0':0;
            dp[i+1][j+1]=dp[i][j]+dp[i+1][j]+dp[i][j+1]+inc;
        }
        return dp[m][n].val>=0?vi{int(dp[m][n].val%MOD),dp[m][n].cnt}:vi{0,0};
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<string>board{"E23","2X2","12S"};
    auto ans=sol.pathsWithMaxScore(board);
    DBGV(ans);

    system("pause");
    return 0;
}
