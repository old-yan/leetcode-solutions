#include "utils.h"

//这是我自己的做法，利用atan2求角度
class Solution0 {
public:
    vector<vector<int>> outerTrees(vector<vector<int>>&points) {
        vector<bool>visited(points.size(),false);
        int bottomLeft=min_element(ALL(points))-points.begin();
        vvi ans;
        long double curangle=-PI/2;
        int cur=bottomLeft;
        visited[bottomLeft]=true;
        ans.emplace_back(points[cur]);
        while(true){
            auto counterClockwise=[&](int x,int y){
                long double a=atan2(points[x][1]-points[cur][1],points[x][0]-points[cur][0]);
                long double b=atan2(points[y][1]-points[cur][1],points[y][0]-points[cur][0]);
                if(a==b)return abs(points[x][1]-points[cur][1])+abs(points[x][0]-points[cur][0])<abs(points[y][1]-points[cur][1])+abs(points[y][0]-points[cur][0]);
                else return fmod(a+PI*2-curangle,PI*2)<fmod(b+PI*2-curangle,PI*2);
            };
            int next=-1;
            REP(j,points.size()){
                if(visited[j])continue;
                if(next<0||counterClockwise(j,next))next=j;
            }
            if(next<0)break;
            if(cur!=bottomLeft&&counterClockwise(bottomLeft,next))break;
            curangle=atan2(points[next][1]-points[cur][1],points[next][0]-points[cur][0]);
            cur=next;
            visited[cur]=true;
            ans.emplace_back(points[cur]);
        }
        return ans;
    }
};

//官方解法1 Jarvis算法，和我的差不多，但是利用解析几何方法做定性判断，比atan2求精确角度的效率要高
class Solution1 {
public:
    vector<vector<int>> outerTrees(vector<vector<int>>&points) {
        vector<bool>visited(points.size(),false);
        int bottomLeft=min_element(ALL(points))-points.begin();
        int cur=bottomLeft;
        visited[cur]=true;
        auto counterClockwiseOrShorter=[&](int cur,int next,int query){
            int res=getDirection(&points[cur][0],&points[next][0],&points[query][0]);
            return res==2||res<0;
        };
        while(true){
            int next=-1;
            REP(j,points.size()){
                if(!visited[j]&&(next<0||counterClockwiseOrShorter(cur,next,j)))next=j;
            }
            if(next<0)break;
            if(counterClockwiseOrShorter(cur,next,bottomLeft))break;
            cur=next;
            visited[cur]=true;
        }
        vvi ans;
        REP(i,points.size()){
            if(visited[i]){
                ans.emplace_back(points[i]);
            }
        }
        return ans;
    }
};

//官方解法2 Graham算法，随便取一个确定在闭包上的点作为初始点即可
class Solution2 {
public:
    vector<vector<int>> outerTrees(vector<vector<int>>&points) {
        if(points.size()<4)return points;
        sort(ALL(points));
        vi bottomLeftPoint=points.back();
        points.pop_back();
        auto counterClockwiseOrShorter=[&](vi&x,vi&y){
            int res=getDirection(&bottomLeftPoint[0],&x[0],&y[0]);
            return res<0||res==2;
        };
        sort(ALL(points),counterClockwiseOrShorter);
        auto Clockwise=[&](int cur,int next,int query){
            int res=getDirection(&points[cur][0],&points[next][0],&points[query][0]);
            return res==4;
        };
        vi S;
        int idx=1;
        while(idx<points.size()&&getDirection(&bottomLeftPoint[0],&points[0][0],&points[idx][0])<0)S.pb(idx++);
        S.pb(0);
        while(idx<points.size()){
            while(S.size()>1&&Clockwise(S[S.size()-2],S.back(),idx))S.pop_back();
            S.pb(idx++);
        }
        vvi ans{bottomLeftPoint};
        for(int a:S)ans.emplace_back(points[a]);
        return ans;
    }
};

//官方解法3 单调链算法，速度最快
class Solution3 {
public:
    vector<vector<int>> outerTrees(vector<vector<int>>&points) {
        int top[101];
        memset(top,0xff,sizeof(top));
        int bottom[101];
        memset(bottom,0xff,sizeof(bottom));
        int mark[2200]={0};
        int left=INT_MAX,right=INT_MIN;
        REP(i,points.size()){
            int x=points[i][0],y=points[i][1];
            chmin(left,x);
            chmax(right,x);
            if(top[x]<0||y>points[top[x]][1])top[x]=i;
            if(bottom[x]<0||y<points[bottom[x]][1])bottom[x]=i;
        }
        auto Clockwise=[&](int cur,int next,int query){
            return getDirection(&points[cur][0],&points[next][0],&points[query][0])==4;
        };
        auto counterClockwise=[&](int cur,int next,int query){
            return getDirection(&points[cur][0],&points[next][0],&points[query][0])==2;
        };
        vi S1,S2;
        FOR(i,left,right+1){
            if(bottom[i]<0)continue;
            while(S1.size()>1&&Clockwise(S1[S1.size()-2],S1.back(),bottom[i])){
                mark[S1.back()]--;
                S1.pop_back();
            }
            S1.pb(bottom[i]);
            mark[S1.back()]++;
            while(S2.size()>1&&counterClockwise(S2[S2.size()-2],S2.back(),top[i])){
                mark[S2.back()]--;
                S2.pop_back();
            }
            S2.pb(top[i]);
            mark[S2.back()]++;
        }
        vvi ans;
        REP(i,points.size()){
            if(mark[i]||points[i][0]==left||points[i][0]==right)ans.emplace_back(points[i]);
        }
        return ans;
    }
};

class Solution:public Solution3{
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi points{
        {3,0},{4,0},{5,0},{6,1},{7,2},{7,3},{7,4},{6,5},{5,5},{4,5},{3,5},{2,5},{1,4},{1,3},{1,2},{2,1},{4,2},{0,3}
    };
    auto ans=sol.outerTrees(points);
    DBGVV(ans);

    system("pause");
    return 0;
}
