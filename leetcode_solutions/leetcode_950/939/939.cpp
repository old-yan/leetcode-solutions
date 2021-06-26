#include "utils.h"

class Solution {
    unordered_set<ll>S;
public:
    int minAreaRect(vector<vector<int>>& points) {
        for(auto&p:points){
            int i=p[0],j=p[1];
            S.insert(i*50000+j);
        }
        int ans=INT_MAX;
        REP(i,points.size()){
            int x0=points[i][0],y0=points[i][1];
            REP(j,i){
                int x1=points[j][0],y1=points[j][1];
                if(x1!=x0&&y1!=y0){
                    if(S.count(x0*50000+y1)&&S.count(x1*50000+y0)){
                        chmin(ans,abs((x1-x0)*(y1-y0)));
                    }
                }
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi points=makevvi("[[1,1],[1,3],[3,1],[3,3],[2,2]]");
    auto ans=sol.minAreaRect(points);
    DBG(ans);

    system("pause");
    return 0;
}
