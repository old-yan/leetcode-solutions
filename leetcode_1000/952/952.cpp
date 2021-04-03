#include "Union.h"
#include "utils.h"

class Solution {
public:
    int largestComponentSize(vector<int>& A) {
        Union u(A.size());
        unordered_map<int,int>M;
        REP(i,A.size()){
            auto v=getFactor(A[i],3200);
            for(int a:v){
                if(M.count(a)){
                    u.unite(i,M[a]);
                }
                else M[a]=i;
            }
        }
        int ans=0;
        REP(i,A.size()){
            if(u.Find(i)==i)chmax(ans,u.size[i]);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi A{4,6,15,35};
    auto ans=sol.largestComponentSize(A);
    DBG(ans);

    system("pause");
    return 0;
}
