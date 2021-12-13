#include "utils.h"

class Solution {
public:
    //由于本题数据很小，所以可以穷举每一个点作为起点的状况
    //注意本题不能用并查集，因为传播关系是单向的
    int maximumDetonation(vector<vector<int>>& bombs) {
        int ans=0;
        int n=bombs.size();
        auto can_reach=[&](int a,int b){
            long long dx=bombs[a][0]-bombs[b][0];
            long long dy=bombs[a][1]-bombs[b][1];
            long long r=bombs[a][2];
            return dx*dx+dy*dy<=r*r;
        };
        for(int i=0;i<n;i++){
            vector<bool>visit(n,false);
            queue<int>Q;
            visit[i]=true,Q.push(i);
            while(Q.size()){
                auto p=Q.front();
                Q.pop();
                for(int j=0;j<n;j++){
                    if(can_reach(p,j) and !visit[j]){
                        visit[j]=true,Q.push(j);
                    }
                }
            }
            ans=max(ans,int(count(visit.begin(),visit.end(),true)));
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<vector<int>>bombs=makevvi("[[1,2,3],[2,3,1],[3,4,2],[4,5,3],[5,6,4]]");
    auto ans=sol.maximumDetonation(bombs);
    DBG(ans);

    system("pause");
    return 0;
}