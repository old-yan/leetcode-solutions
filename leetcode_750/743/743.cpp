#include "utils.h"

class Solution {
    #define INF 0x3f3f3f3f
    int dis_matrix[101][101];
    int mindis[101];
    bool visited[101]={0};
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        fill(dis_matrix[0],dis_matrix[n+1],INF);
        fill(mindis,mindis+n+1,INF);
        for(auto&time:times){
            dis_matrix[time[0]][time[1]]=time[2];
        }
        mindis[k]=0;
        while(true){
            int near=-1;
            for(int i=1;i<=n;i++){
                if(!visited[i]&&(near<0||mindis[i]<mindis[near]))near=i;
            }
            if(near<0||mindis[near]==INF)break;
            visited[near]=true;
            for(int i=1;i<=n;i++){
                mindis[i]=min(mindis[i],mindis[near]+dis_matrix[near][i]);
            }
        }
        int Max=*max_element(mindis+1,mindis+n+1);
        if(Max==INF)return -1;
        else return Max;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi times=makevvi("[[2,1,1],[2,3,1],[3,4,1]]");
    int n=4;
    int k=2;
    auto ans=sol.networkDelayTime(times,n,k);
    DBG(ans);

    system("pause");
    return 0;
}
