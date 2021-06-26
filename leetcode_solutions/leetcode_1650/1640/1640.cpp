#include "utils.h"

class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        int pos[101];
        memset(pos,0xff,sizeof(pos));
        REP(i,arr.size())pos[arr[i]]=i;
        for(auto&p:pieces){
            for(int a:p)if(pos[a]<0)return false;
            FOR(i,1,p.size()){
                if(pos[p[i]]!=pos[p[i-1]]+1)return false;
            }
        }
        return true;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi arr{15,88};
    vvi pieces=makevvi("[[88],[15]]");
    auto ans=sol.canFormArray(arr,pieces);
    DBG(ans);

    system("pause");
    return 0;
}
