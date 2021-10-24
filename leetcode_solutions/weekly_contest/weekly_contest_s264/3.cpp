#include "utils.h"

class Solution {
public:
    int countHighestScoreNodes(vector<int>& parents) {
        int n=parents.size();
        vector<int>sons[n];
        for(int i=1;i<n;i++){
            sons[parents[i]].push_back(i);
        }
        //第一次 dfs 找出所有子树的大小，将结果保存到 size 数组
        vector<int>size(n,0);
        function<int(int)>dfs=[&](int cur){
            for(int s:sons[cur])size[cur]+=dfs(s);
            return ++size[cur];
        };
        dfs(0);
        //第二次 dfs 找出所有结点的分数，将结果保存到 score 数组
        vector<long long>score;
        dfs=[&](int cur){
            long long a=1;
            if(cur!=0)a*=n-size[cur];
            for(int s:sons[cur])a*=size[s];
            for(int s:sons[cur])dfs(s);
            score.push_back(a);
            return a;
        };
        dfs(0);
        long long Max=*max_element(score.begin(),score.end());
        return count(score.begin(),score.end(),Max);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<int>parents{-1,2,0,2,0};
    auto ans=sol.countHighestScoreNodes(parents);
    DBG(ans);

    system("pause");
    return 0;
}