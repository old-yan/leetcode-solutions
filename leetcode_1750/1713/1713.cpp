#include "SegTree.h"
#include "utils.h"

SegTree<int>T(100000,[](int x,int y){return max(x,y);});
class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        T.set(0);
        unordered_map<int,int>M;
        REP(i,target.size())M[target[i]]=i;
        for(int a:arr)if(M.count(a)){
            int j=M[a];
            int k=T(0,j-1);
            T.set(j,k+1);
        }
        return target.size()-T.data[1];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi target{5,1,3};
    vi arr{9,4,2,3,4};
    auto ans=sol.minOperations(target,arr);
    DBG(ans);

    system("pause");
    return 0;
}
