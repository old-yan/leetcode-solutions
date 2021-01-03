#include "utils.h"

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        map<int,multiset<int>>M;
        int Max=INT_MIN;
        for(auto&A:envelopes){
            M[A[0]].insert(A[1]);
            chmax(Max,max(A[0],A[1]));
        }
        zkwMaxTree T(Max+1);
        for(auto it=M.rbegin();it!=M.rend();++it){
            auto&v=it->second;
            for(int a:v){
                T.set(a,T(a+1,Max)+1);
            }
        }
        return T(0,Max);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi envelopes{
        {5,4},{6,4},{6,7},{2,3}
    };
    auto ans=sol.maxEnvelopes(envelopes);
    DBG(ans);

    system("pause");
    return 0;
}
