#include "utils.h"

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int ans=0;
        int n=points.size();
        vvi dismatrix(n,vi(n,0));
        REP(i,n){
            REP(j,i){
                int dis=pow(points[j][0]-points[i][0],2)+pow(points[j][1]-points[i][1],2);
                dismatrix[i][j]=dismatrix[j][i]=dis;
            }
        }
        REP(i,n){
            sort(ALL(dismatrix[i]));
            auto next=next_different(dismatrix[i]);
            for(int j=0;j<n;j=next[j]){
                int k=next[j]-j;
                if(k>1)ans+=k*(k-1);
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi points{
        {1,1},{2,2},{3,3}
    };
    auto ans=sol.numberOfBoomerangs(points);
    DBG(ans);

    system("pause");
    return 0;
}
