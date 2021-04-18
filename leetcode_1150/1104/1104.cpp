#include "utils.h"

class Solution {
    vi ans;
    void traverse(int truelabel,int row){
        if(row%2){
            ans.pb(truelabel);
        }
        else{
            ans.pb((1<<(row-1))*3-1-truelabel);
        }
        if(truelabel>1)traverse(truelabel/2,row-1);
    }
public:
    vector<int> pathInZigZagTree(int label) {
        int row=32-__builtin_clz(label);
        int truelabel=row%2?label:(1<<(row-1))*3-1-label;
        traverse(truelabel,row);
        reverse(ALL(ans));
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int label=14;
    auto ans=sol.pathInZigZagTree(label);
    DBGV(ans);

    system("pause");
    return 0;
}
