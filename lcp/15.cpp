#include "utils.h"

class Solution {
public:
    vector<int> visitOrder(vector<vector<int>>& points, string direction) {
        int n=points.size();
        vi ans;
        bool visited[n];
        memset(visited,0,sizeof(visited));
        auto start=min_element(ALL(points));
        visited[start-points.begin()]=true;
        ans.pb(start-points.begin());
        auto cur=&(*start)[0];
        for(char c:direction){
            int choice=-1;
            REP(i,n)if(!visited[i]){
                if(choice<0||getDirection(cur,&points[choice][0],&points[i][0])==(c=='L'?4:2)){
                    choice=i;
                }
            }
            visited[choice]=true;
            ans.pb(choice);
            cur=&points[choice][0];
        }
        REP(i,n)if(!visited[i]){
            ans.pb(i);
            break;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi points=makevvi("[[69,86],[32,1],[100,7],[53,9],[91,64],[5,71],[34,90],[39,90],[53,65],[85,56]]");
    string direction="LRRRRRRL";
    auto ans=sol.visitOrder(points,direction);
    DBGV(ans);

    system("pause");
    return 0;
}
