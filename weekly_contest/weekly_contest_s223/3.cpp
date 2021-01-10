#include "utils.h"

class Solution {
public:
    //本题关键在于想清楚，把allowedSwaps视为连通关系，连通的下标可以随便打乱重排
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n=target.size();
        Union u(n);
        for(auto&A:allowedSwaps){
            int i=A[0],j=A[1];
            //利用并查集进行连通
            u.unite(i,j);
        }
        map<int,unordered_map<int,int>>M;
        REP(i,n){
            //j是下标i的元素所在集的代表元素
            //将source所有元素送到代表元素处，站一块
            int j=u.Find(i);
            M[j][source[i]]++;
        }
        int rest=0;
        REP(i,n){
            //同一集中的source与target元素对应消除
            int j=u.Find(i);
            if(M[j].count(target[i])){
                if(!--M[j][target[i]]){
                    M[j].erase(target[i]);
                }
            }
            else rest++;
        }
        return rest;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi source{5,1,2,4,3};
    vi target{1,5,4,2,3};
    vvi allowedSwaps{
        {0,4},{4,2},{1,3},{1,4}
    };
    auto ans=sol.minimumHammingDistance(source,target,allowedSwaps);
    DBG(ans);

    system("pause");
    return 0;
}
