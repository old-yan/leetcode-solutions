#include "utils.h"

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        sort(ALL(points));
        int ans=0;
        REP(i,points.size()){
            int same=1;
            vvi angles;
            FOR(j,i+1,points.size()){
                int dy=points[j][1]-points[i][1],dx=points[j][0]-points[i][0];
                if(!dx){
                    if(dy){
                        dy=1;
                    }
                    else{
                        same++;
                        continue;
                    }
                }
                else{
                    if(dy){
                        ll temp=gcd(dx,dy);
                        dx/=temp;
                        dy/=temp;
                    }
                    else{
                        dx=1;
                    }
                }
                angles.pb({dx,dy});
            }
            sort(ALL(angles));
            int maxsame=same;
            for(int j=0,k;j<angles.size();j=k){
                for(k=j+1;k<angles.size()&&angles[k]==angles[j];k++);
                chmax(maxsame,same+k-j);
            }
            chmax(ans,maxsame);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi points{{0,0},{94911151,94911150},{94911152,94911151}};
    auto ans=sol.maxPoints(points);
    DBG(ans);

    system("pause");
    return 0;
}
