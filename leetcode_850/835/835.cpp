#include "utils.h"

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int m=img1.size(),n=m*2-1;
        bitset<5400>b1,b2;
        REP(i,m){
            REP(j,m){
                if(img1[i][j])b1.set(m*n+i*n+j);
            }
        }
        REP(i,m){
            REP(j,m){
                if(img2[i][j])b2.set(i*n+j);
            }
        }
        int ans=0;
        REP(i,m*2){
            REP(j,n){
                chmax(ans,int((b1&b2).count()));
                b2<<=1;
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi A=makevvi("[[1,1,0],[0,1,0],[0,1,0]]");
    vvi B=makevvi("[[0,0,0],[0,1,1],[0,0,1]]");
    auto ans=sol.largestOverlap(A,B);
    DBG(ans);

    system("pause");
    return 0;
}
