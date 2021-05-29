#include "Graph.h"
#include "utils.h"

class Solution {
    int di[4]={0,0,-1,-1},dj[4]={-1,1,-1,1};
public:
    int maxStudents(vector<vector<char>>& seats) {
        int m=seats.size(),n=seats[0].size();
        fn.reset(m*n+2);
        int cnt=0;
        REP(i,m)REP(j,n)if(seats[i][j]=='.'){
            cnt++;
            if(j%2)fn.addEdge(m*n,i*n+j,1);
            else fn.addEdge(i*n+j,m*n+1,1);
            REP(k,4){
                int ii=i+di[k],jj=j+dj[k];
                if(!VALID||seats[ii][jj]!='.')continue;
                if(j%2)fn.addEdge(i*n+j,ii*n+jj,1);
                else fn.addEdge(ii*n+jj,i*n+j,1);
            }
        }
        return cnt-Dinic(m*n,m*n+1,fn);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<vector<char>>seats{
        {'#','.','.'},
        {'.','#','.'}
    };
    auto ans=sol.maxStudents(seats);
    DBG(ans);

    system("pause");
    return 0;
}