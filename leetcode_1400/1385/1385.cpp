#include "SegTree.h"
#include "utils.h"

SegTree<int>T(3000,[](int x,int y){return x|y;});
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        T.set(0);
        for(int a:arr2)T.set(a+1100,1);
        int ans=0;
        for(int a:arr1){
            if(!T(a+1100-d,a+1100+d))ans++;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi arr1{4,5,8};
    vi arr2{10,9,1,8};
    int d=2;
    auto ans=sol.findTheDistanceValue(arr1,arr2,d);
    DBG(ans);

    system("pause");
    return 0;
}
