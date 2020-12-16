#include "utils.h"

class Solution {
    vi ans;
    void dfs(int i,int&val,bool curstate){
        if(i<0){
            ans.pb(val);
        }
        else{
            if(curstate){
                dfs(i-1,val,false);
                val-=(1<<i);
                dfs(i-1,val,true);
            }
            else{
                dfs(i-1,val,false);
                val+=(1<<i);
                dfs(i-1,val,true);
            }
        }
    }
public:
    vector<int> grayCode(int n) {
        int val=0;
        dfs(n-1,val,false);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=3;
    auto ans=sol.grayCode(n);
    DBGV(ans);

    system("pause");
    return 0;
}

//  0   0   0
//  0   0   1
//  0   1   1
//  0   1   0
//  1   1   0
//  1   1   1
//  1   0   1
//  1   0   0
