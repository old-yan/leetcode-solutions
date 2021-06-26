#include "utils.h"

class Solution {
public:
    int numSquares(int n) {
        int r=sqrt(n);
        if(n==r*r)return 1;
        vector<int>Squares;
        bool isSquare[n+1];
        memset(isSquare,0,sizeof(isSquare));
        bool visited[n+1];
        memset(visited,0,sizeof(visited));
        FOR(i,1,r+1){
            Squares.pb(i*i);
            isSquare[i*i]=true;
        }
        queue<int>Q;
        Q.push(n);
        visited[n]=true;
        int level=1;
        while(int l=Q.size()){
            level++;
            while(l--){
                int a=Q.front();
                Q.pop();
                for(int b:Squares){
                    if(b>a)break;
                    if(isSquare[a-b])return level;
                    Q.push(a-b);
                    visited[a-b]=true;
                }
            }
        }
        return -1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=87;
    auto ans=sol.numSquares(n);
    DBG(ans);

    system("pause");
    return 0;
}
