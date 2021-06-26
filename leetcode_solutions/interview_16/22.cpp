#include "utils.h"

bool _isblack[2000][2000];
#define isblack(i,j) _isblack[i+1800][j+1800]
class Solution {
public:
    vector<string> printKMoves(int K) {
        memset(_isblack,0,sizeof(_isblack));
        int i=0,j=0,k=0;
        int top=0,bottom=0,left=0,right=0;
        while(K--){
            if(!isblack(i,j)){
                isblack(i,j)=true;
                k=(k+3)%4;
            }
            else{
                isblack(i,j)=false;
                k=(k+1)%4;
            }
            i+=di[k];
            j+=dj[k];
            chmin(top,i);
            chmax(bottom,i);
            chmin(left,j);
            chmax(right,j);
        }

        vector<string>ans(bottom-top+1,string(right-left+1,'_'));
        FOR(i,top,bottom+1){
            FOR(j,left,right+1){
                if(isblack(i,j)){
                    ans[i-top][j-left]='X';
                }
            }
        }
        char dir[4]={'R','U','L','D'};
        ans[i-top][j-left]=dir[k];
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int K=2;
    auto ans=sol.printKMoves(K);
    DBGV(ans);

    system("pause");
    return 0;
}
