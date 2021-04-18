#include "utils.h"

class Solution {
    vi v;
    int Min(){
        int d1=v[1]-v[0],d2=v[2]-v[1];
        if(d1==1&&d2==1)return 0;
        else if(d1==1||d2==1||d1==2||d2==2)return 1;
        else return 2;
    }
    int Max(){
        return v[2]-v[0]-2;
    }
public:
    vector<int> numMovesStones(int a, int b, int c) {
        v.assign({a,b,c});
        sort(ALL(v));
        return {Min(),Max()};
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int a=1;
    int b=2;
    int c=5;
    auto ans=sol.numMovesStones(a,b,c);
    DBGV(ans);

    system("pause");
    return 0;
}
