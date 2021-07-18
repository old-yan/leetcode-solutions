#include "Trie.h"
#include "utils.h"

BiTrie<17>T;
class Solution {
    vi sons[100000];
    vi ans;
    vi toans[100000];
    void dfs(int cur,vvi&queries){
        T.insert(cur);
        for(int q:toans[cur])
            ans[q]=T.MaxXor(0xffffffff^queries[q][1]);
        for(int a:sons[cur])
            dfs(a,queries);
        T.erase(cur);
    }
public:
    // 这道题，对于每个结点，要在该结点到根的路径上找答案
    // 想到了什么？想到了从根到叶的路径的题目！没错，在对树进行遍历的时候，只要进结点push，出结点pop，就可以动态维护路径
    // 这道题有一点变化，那就是答案不是路径，而是与路径上的数字的最大异或值，那么只要把路径上的数字加到字典树里就可以查询答案了
    vector<int> maxGeneticDifference(vector<int>& parents, vector<vector<int>>& queries) {
        T.clear();
        //建树，找根
        int root;
        for(int i=0;i<parents.size();i++){
            if(parents[i]>=0)sons[parents[i]].push_back(i);
            else root=i;
        }
        //在每个结点的位置，回答针对这个结点的query，为了知道要回答哪些query，所以先生成toans数组
        ans.resize(queries.size());
        for(int i=0;i<queries.size();i++)
            toans[queries[i][0]].push_back(i);
        //在dfs的同时，对字典树进行维护，利用字典树回答问题
        dfs(root,queries);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi parents{-1,0,1,1};
    vvi queries=makevvi("[[0,2],[3,2],[2,5]]");
    auto ans=sol.maxGeneticDifference(parents,queries);
    DBGV(ans);

    system("pause");
    return 0;
}
