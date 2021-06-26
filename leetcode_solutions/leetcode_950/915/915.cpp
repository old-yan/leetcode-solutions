#include "utils.h"

class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        multiset<int>S;
        for(int a:A)S.insert(a);
        int curMax=0;
        for(int a:A){
            chmax(curMax,a);
            S.erase(S.find(a));
            if(*S.begin()>=curMax)return A.size()-S.size();
        }
        return -1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi A{5,0,3,8,6};
    auto ans=sol.partitionDisjoint(A);
    DBG(ans);

    system("pause");
    return 0;
}
