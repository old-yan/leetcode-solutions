#include "Union.h"
#include "utils.h"

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n=row.size();
        Union u(n/2);
        for(int i=0;i<n;i+=2){
            u.unite(row[i]/2,row[i+1]/2);
        }
        int ans=0;
        REP(i,n/2){
            if(u.Find(i)==i){
                ans+=u.size[i]-1;
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi row{0,2,1,3};
    auto ans=sol.minSwapsCouples(row);
    DBG(ans);

    system("pause");
    return 0;
}
