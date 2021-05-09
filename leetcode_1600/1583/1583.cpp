#include "utils.h"

class Solution {
    int score[500][500];
    bool unhappy(int x,int y,int u,int v){
        return score[x][u]>score[x][y]&&score[u][x]>score[u][v];
    }
public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        bitset<500>b;
        REP(i,n){
            REP(j,n-1){
                score[i][preferences[i][j]]=-j;
            }
        }
        REP(i,pairs.size()){
            int x=pairs[i][0],y=pairs[i][1];
            REP(j,i){
                int x2=pairs[j][0],y2=pairs[j][1];
                if(unhappy(x,y,x2,y2)){
                    b.set(x);
                    b.set(x2);
                }
                if(unhappy(x,y,y2,x2)){
                    b.set(x);
                    b.set(y2);
                }
                if(unhappy(y,x,x2,y2)){
                    b.set(y);
                    b.set(x2);
                }
                if(unhappy(y,x,y2,x2)){
                    b.set(y);
                    b.set(y2);
                }
            }
        }
        return b.count();
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=4;
    vvi preferences=makevvi("[[1, 2, 3], [3, 2, 0], [3, 1, 0], [1, 2, 0]]");
    vvi pairs=makevvi("[[0, 1], [2, 3]]");
    auto ans=sol.unhappyFriends(n,preferences,pairs);
    DBG(ans);

    system("pause");
    return 0;
}
