#include "utils.h"

class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vi seq(m);
        iota(ALL(seq),1);
        vi ans;
        for(auto&q:queries){
            int idx;
            for(idx=0;seq[idx]!=q;idx++);
            ans.pb(idx);
            memmove(&seq[1],&seq[0],idx*4);
            seq[0]=q;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi queries{3,1,2,1};
    int m=5;
    auto ans=sol.processQueries(queries,m);
    DBGV(ans);

    system("pause");
    return 0;
}
