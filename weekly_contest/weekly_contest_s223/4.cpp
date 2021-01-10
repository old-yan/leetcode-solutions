#include "utils.h"

class Solution {
    int n,k;
    vector<int>jobs;
    int ans=INT_MAX;
    int sum[12]={0};
    bool used[12]={0};
    //贪心+回溯，idx为货物的编号，curmax为目前为止的最大和
    void dfs(int idx,int curmax){
        //idx==n时，本次货物安排完毕
        if(idx==n){
            ans=min(ans,curmax);
        }
        else{
            //利用小根堆，按照和从小到大的顺序进行试探
            auto comp=[&](int x,int y){return sum[x]>sum[y];};
            priority_queue<int,vector<int>,decltype(comp)>Q(comp);
            for(int i=0;i<k;i++)Q.push(i);
            //利用pre记录上一个试探的和值，如果一样就不重复试探了
            int pre;
            for(int i=0;i<k;i++){
                int j=Q.top();
                Q.pop();
                //剪枝
                if(sum[j]+jobs[idx]>=ans)break;
                if(!i||sum[j]!=pre){
                    sum[j]+=jobs[idx];
                    dfs(idx+1,max(sum[j],curmax));
                    sum[j]-=jobs[idx];
                    pre=sum[j];
                }
            }
        }
    }
public:
    int minimumTimeRequired(vector<int>&_jobs, int _k) {
        k=_k;
        jobs=_jobs;
        n=jobs.size();
        //将货物降序排列
        sort(jobs.begin(),jobs.end(),greater<int>());
        dfs(0,0);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi jobs{254,256,256,254,251,256,254,253,255,251,251,255};
    int k=10;
    auto ans=sol.minimumTimeRequired(jobs,k);
    DBG(ans);

    system("pause");
    return 0;
}
