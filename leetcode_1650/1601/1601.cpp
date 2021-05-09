#include "utils.h"

class Solution {
    struct{
        int deg[20]={0},cnt=0;
        void add(int i){
            if(++deg[i]==0)cnt--;
            else if(deg[i]==1)cnt++;
        }
        void sub(int i){
            if(--deg[i]==0)cnt--;
            else if(deg[i]==-1)cnt++;
        }
    }counter;
    int ans=0;
    void dfs(int cur,int curnum,vvi&requests){
        if(cur==requests.size()){
            if(!counter.cnt)chmax(ans,curnum);
        }
        else{
            dfs(cur+1,curnum,requests);
            int from=requests[cur][0],to=requests[cur][1];
            counter.add(to),counter.sub(from);
            dfs(cur+1,curnum+1,requests);
            counter.add(from),counter.sub(to);
        }
    }
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        dfs(0,0,requests);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=3;
    vvi requests=makevvi("[[0,0],[1,2],[2,1]]");
    auto ans=sol.maximumRequests(n,requests);
    DBG(ans);

    system("pause");
    return 0;
}
