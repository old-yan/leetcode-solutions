#include "utils.h"

class Solution {
public:
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        int sum[51][51],ansx=0,ansy=0,anssum=0;
        REP(i,51)REP(j,51){
            sum[i][j]=0;
            for(auto&t:towers){
                double dis=sqrt(pow(t[0]-i,2)+pow(t[1]-j,2));
                if(dis>radius)continue;
                sum[i][j]+=t[2]/(1+dis);
            }
            if(chmax(anssum,sum[i][j])){
                ansx=i,ansy=j;
            }
        }
        return {ansx,ansy};
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi towers=makevvi("[[1,2,5],[2,1,7],[3,1,9]]");
    int radius=2;
    auto ans=sol.bestCoordinate(towers,radius);
    DBGV(ans);

    system("pause");
    return 0;
}
