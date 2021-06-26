#include "utils.h"

class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        vector<double>v;
        int now=0;
        for(auto&p:points){
            if(p==location)now++;
            else v.pb(atan2(p[1]-location[1],p[0]-location[0])*180/PI);
        }
        sort(ALL(v));
        v.insert(v.end(),ALL(v));
        FOR(i,v.size()/2,v.size())v[i]+=360;
        int ans=0;
        for(int i=0,j=0;i<v.size()/2;i++){
            while(v[j]<=v[i]+angle+EPS)j++;
            chmax(ans,j-i);
        }
        return ans+now;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi points=makevvi("[[2,1],[2,2],[3,3]]");
    int angle=90;
    vi location{1,1};
    auto ans=sol.visiblePoints(points,angle,location);
    DBG(ans);

    system("pause");
    return 0;
}
