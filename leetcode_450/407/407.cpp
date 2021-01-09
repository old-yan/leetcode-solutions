#include "utils.h"

class Solution {
    class surface{
    public:
        int i,j,h;
        surface(int _i,int _j,int _h):i(_i),j(_j),h(_h){}
    };
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m=heightMap.size(),n=heightMap[0].size();
        auto comp=[&](surface*x,surface*y){return x->h>y->h;};
        priority_queue<surface*,vector<surface*>,decltype(comp)>Q(comp);
        bool visited[m][n];
        memset(visited,0,sizeof(visited));
        REP(j,n){
            if(!visited[0][j]){
                Q.emplace(new surface(0,int(j),heightMap[0][j]));
                visited[0][j]=true;
            }
            if(!visited[m-1][j]){
                Q.emplace(new surface(m-1,int(j),heightMap[m-1][j]));
                visited[m-1][j]=true;
            }
        }
        FOR(i,1,m-1){
            if(!visited[i][0]){
                Q.emplace(new surface(int(i),0,heightMap[i][0]));
                visited[i][0]=true;
            }
            if(!visited[i][n-1]){
                Q.emplace(new surface(int(i),n-1,heightMap[i][n-1]));
                visited[i][n-1]=true;
            }
        }
        int ans=0;
        while(Q.size()){
            auto a=Q.top();
            Q.pop();
            REP(k,4){
                int ii=a->i+di[k],jj=a->j+dj[k];
                if(ii>=0&&ii<m&&jj>=0&&jj<n&&!visited[ii][jj]){
                    ans+=max(a->h,heightMap[ii][jj])-heightMap[ii][jj];
                    Q.emplace(new surface(ii,jj,max(a->h,heightMap[ii][jj])));
                    visited[ii][jj]=true;
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

    vvi heightMap{
        {1,4,3,1,3,2},
        {3,2,1,3,2,4},
        {2,3,3,2,3,1}
    };
    auto ans=sol.trapRainWater(heightMap);
    DBG(ans);

    system("pause");
    return 0;
}
