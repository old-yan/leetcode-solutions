#include "utils.h"

class Solution {
    struct node{
        int idx[40]={0},sum=0;
        bool operator<(const node&other)const{
            if(sum!=other.sum)return sum>other.sum;
            REP(i,40){
                if(idx[i]!=other.idx[i])return idx[i]>other.idx[i];
            }
            return false;
        }
    };
    int m,n;
    set<node>S;
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        m=mat.size(),n=mat[0].size();
        priority_queue<node>Q;
        node first;
        REP(i,m)first.sum+=mat[i][0];
        Q.emplace(first);
        while(true){
            auto p=Q.top();
            Q.pop();
            if(!S.insert(p).second)continue;
            if(!--k)return p.sum;
            REP(i,m){
                if(++p.idx[i]<n){
                    p.sum+=mat[i][p.idx[i]]-mat[i][p.idx[i]-1];
                    Q.push(p);
                    p.sum-=mat[i][p.idx[i]]-mat[i][p.idx[i]-1];
                }
                p.idx[i]--;
            }
        }
        return -1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi mat=makevvi("[[1,3,11],[2,4,6]]");
    int k=5;
    auto ans=sol.kthSmallest(mat,k);
    DBG(ans);

    system("pause");
    return 0;
}
